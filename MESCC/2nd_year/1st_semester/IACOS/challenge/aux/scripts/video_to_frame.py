import cv2
import os
'''
Missing:

6. joao mario
7. mario
'''

# Definir variável de ambiente OPENCV_FFMPEG_READ_ATTEMPTS
os.environ['OPENCV_FFMPEG_READ_ATTEMPTS'] = '16384'

# Path to the input video file
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/1.Forward/mario.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/1.Forward/carlos.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/1.Forward/joao.mp4'

#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/2.Right/mario.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/2.Right/carlos.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/2.Right/joao.mp4'

#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/3.Left/mario.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/3.Left/carlos.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/3.Left/joao.mp4'

#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/4.Stop/mario.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/4.Stop/carlos.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/4.Stop/joao.mp4'

#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/5.MoreSpeed/mario.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/5.MoreSpeed/carlos.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/5.MoreSpeed/joao.mp4'

#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/6.LessSpeed/mario.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/6.LessSpeed/carlos.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/6.LessSpeed/joao.mp4'

#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/7.Invert/mario.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/7.Invert/carlos.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/7.Invert/joao.mp4'

#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/8.StartRoadWork/video1.mp4'
#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/8.StartRoadWork/video2.mp4'


#video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/9. EndRoadWork/video1.mp4'
video_path = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/9. EndRoadWork/video2.mp4'

# Directory to save the frames
#output_directory = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/7.Invert/Frames/mario'
#output_directory = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/7.Invert/Frames/carlos'
#output_directory = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/7.Invert/Frames/mario'

#output_directory = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/8.StartRoadWork/Frames/video1'
#output_directory = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/8.StartRoadWork/Frames/video2'

#output_directory = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/9. EndRoadWork/Frames/video1'
output_directory = '/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/9. EndRoadWork/Frames/video2'





# Create the output directory if it doesn't exist
os.makedirs(output_directory, exist_ok=True)

# Open the video file
cap = cv2.VideoCapture(video_path)

# Check if the video file is opened successfully
if not cap.isOpened():
    print("Error: Couldn't open the video file.")
    exit()

# Get the frames per second (fps) of the video
fps = cap.get(cv2.CAP_PROP_FPS)

# Loop through the video frames
frame_count = 0
while True:
    # Read a frame from the video
    ret, frame = cap.read()

    # Break the loop if the video is finished
    if not ret:
        break

    # Save the frame as an image file
    frame_count += 1
    frame_filename = f"{output_directory}/frame_{frame_count:04d}.jpg"
    cv2.imwrite(frame_filename, frame)

    # Display the frame (optional, you can comment this out if not needed)
    cv2.imshow('Frame', frame)
    
    # Break the loop if 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the video capture object and close the OpenCV windows
cap.release()
cv2.destroyAllWindows()

print(f"Frames saved to {output_directory}")
