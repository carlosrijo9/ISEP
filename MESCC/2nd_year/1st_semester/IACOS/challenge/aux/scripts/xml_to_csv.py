import os
import glob
import pandas as pd
import xml.etree.ElementTree as ET

def xml_to_csv(path):
    xml_list = []
    for xml_file in glob.glob(os.path.join(path, '*.xml')):
        tree = ET.parse(xml_file)
        root = tree.getroot()
        for member in root.findall('object'):
            value = (
                root.find('filename').text,
                int(root.find('size')[0].text),
                int(root.find('size')[1].text),
                member[0].text,
                int(member[4][0].text),
                int(member[4][1].text),
                int(member[4][2].text),
                int(member[4][3].text)
            )
            xml_list.append(value)
    column_name = ['filename', 'width', 'height', 'class', 'xmin', 'ymin', 'xmax', 'ymax']
    xml_df = pd.DataFrame(xml_list, columns=column_name)
    return xml_df

def main():
    image_dir = '/home/mario/Desktop/IACOS/RealTimeObjectDetection/Tensorflow/workspace/images'
    for folder in ['train', 'test']:
        folder_path = os.path.join(image_dir, folder)
        xml_df = xml_to_csv(folder_path)
        csv_filename = os.path.join(image_dir, f'{folder}_labels.csv')
        xml_df.to_csv(csv_filename, index=None)
    print('Successfully converted xml to csv.')

main()
