import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import cv2
import mediapipe as mp
import numpy as np

class HandGesturePublisher(Node):
    def __init__(self):
        super().__init__('hand_gesture_publisher')
        self.publisher_ = self.create_publisher(String, '/atc', 10)
        self.timer = self.create_timer(0.1, self.publish_hand_gesture)
        self.mp_hands = mp.solutions.hands
        self.hands = self.mp_hands.Hands(static_image_mode=False, max_num_hands=1, min_detection_confidence=0.7, min_tracking_confidence=0.7)
        self.mp_drawing = mp.solutions.drawing_utils
        self.cap = cv2.VideoCapture(0)
        self.command_old = 'Unknown Gesture'

    def determine_hand_orientation(self, hand_landmarks, image_width, image_height):
        wrist = hand_landmarks.landmark[self.mp_hands.HandLandmark.WRIST]
        middle_mcp = hand_landmarks.landmark[self.mp_hands.HandLandmark.MIDDLE_FINGER_MCP]

        wrist_coords = np.array([wrist.x * image_width, wrist.y * image_height])
        middle_mcp_coords = np.array([middle_mcp.x * image_width, middle_mcp.y * image_height])

        line_angle = np.degrees(np.arctan2(middle_mcp_coords[1] - wrist_coords[1], middle_mcp_coords[0] - wrist_coords[0]))

        if line_angle > 45 and line_angle < 135:
            return 'Downwards'
        elif line_angle < -45 and line_angle > -135:
            return 'Upwards'
        elif line_angle <= 45 and line_angle >= -45:
            return 'Rightwards'
        else:
            return 'Leftwards'

    def identify_hand_type(self, results, hand_index):
        if results.multi_handedness[hand_index].classification[0].label == 'Left':
            return 'Left'
        return 'Right'

    def recognize_gesture(self, hand_landmarks, hand_orientation, hand_type):
        thumb_tip = hand_landmarks.landmark[self.mp_hands.HandLandmark.THUMB_TIP]
        index_tip = hand_landmarks.landmark[self.mp_hands.HandLandmark.INDEX_FINGER_TIP]
        index_mcp = hand_landmarks.landmark[self.mp_hands.HandLandmark.INDEX_FINGER_MCP]
        middle_tip = hand_landmarks.landmark[self.mp_hands.HandLandmark.MIDDLE_FINGER_TIP]
        ring_tip = hand_landmarks.landmark[self.mp_hands.HandLandmark.RING_FINGER_TIP]
        pinky_tip = hand_landmarks.landmark[self.mp_hands.HandLandmark.PINKY_TIP]

        command_new = 'Unknown Gesture'

        if hand_orientation == 'Upwards':
            if (index_tip.y < index_mcp.y and
                middle_tip.y > index_mcp.y and
                ring_tip.y > index_mcp.y and
                pinky_tip.y > index_mcp.y):
                command_new = 'Invert'
            elif hand_type == 'Right':
                if thumb_tip.x < index_tip.x:
                    command_new = 'Stop'
                else:
                    command_new = 'Forward'
            else:  # Left hand
                if thumb_tip.x > index_tip.x:
                    command_new = 'Stop'
                else:
                    command_new = 'Forward'
        elif hand_orientation == 'Leftwards':
            command_new = 'Turn Left'
        elif hand_orientation == 'Rightwards':
            command_new = 'Turn Right'
        elif hand_orientation == 'Downwards':
            command_new = 'Slow Down'

        if self.command_old != command_new:
            self.command_old = command_new
            return command_new
        # else:
        #     return 'Unknown Gesture'

    def publish_hand_gesture(self):
        ret, frame = self.cap.read()
        if not ret:
            return
        frame = cv2.flip(frame, 1)
        frame_height, frame_width, _ = frame.shape
        rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        results = self.hands.process(rgb_frame)

        if results.multi_hand_landmarks:
            for i, hand_landmarks in enumerate(results.multi_hand_landmarks):
                self.mp_drawing.draw_landmarks(frame, hand_landmarks, self.mp_hands.HAND_CONNECTIONS)
                hand_orientation = self.determine_hand_orientation(hand_landmarks, frame_width, frame_height)
                hand_type = self.identify_hand_type(results, i)
                gesture = self.recognize_gesture(hand_landmarks, hand_orientation, hand_type)
                if isinstance(gesture, str):  # Check if gesture is a string before publishing
                    self.publisher_.publish(String(data=gesture))
                cv2.putText(frame, gesture,(10, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 0, 0), 2, cv2.LINE_AA)
        
        cv2.imshow('Hand Gestures', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            self.cap.release()
            cv2.destroyAllWindows()

def main(args=None):
    rclpy.init(args=args)
    hand_gesture_publisher = HandGesturePublisher()
    rclpy.spin(hand_gesture_publisher)
    hand_gesture_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()