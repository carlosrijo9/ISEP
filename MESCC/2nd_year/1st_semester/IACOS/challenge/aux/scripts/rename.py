import os

def rename_files_in_folder(folder_path):
    for filename in os.listdir(folder_path):
        if "frame" in filename:
            new_filename = filename.replace("frame_", "forward_joao_")
            old_path = os.path.join(folder_path, filename)
            new_path = os.path.join(folder_path, new_filename)
            os.rename(old_path, new_path)
            print(f"Renomeado: {filename} -> {new_filename}")

if __name__ == "__main__":
    folder_path = "/home/mario/Desktop/IACOS/Tensorflow/workspace/images/collectedimages/1.Forward/Frames/João"
    rename_files_in_folder(folder_path)
