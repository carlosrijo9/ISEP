1st Model: https://studio.edgeimpulse.com/studio/321763
2nd Model: https://studio.edgeimpulse.com/studio/321984

Dataset Creation
First Model Dataset
To initiate the model development, a dataset was created for the first model. Utilizing numerous videos capturing the desired hand movements, a Python script was crafted to extract frames from the videos.

The initial dataset for the first model comprised approximately 400 images, with an 80% training and 20% testing split. All images underwent labeling using the Label Image program. Following the completion of labeling, specific Neural Network settings and training configurations were defined:

Neural Network settings:

Model size: Large (46.5M params, 89.3 MB)
Batch size: 16
Training settings:

Number of training cycles: 30
Validation set size: 20%
Split train/validation set on metadata key
Profile int8 model
After 30 training cycles, the model achieved a training precision of 94.2%.

Model Testing
Subsequent model testing yielded a precision of 97.2%, with only 2 false positives detected among all testing images.

Iterative Model Development
Upon integration into the ongoing development program, an associated error emerged. Suspecting a direct link to the model, a new model was created, consisting of a reduced dataset of 90 items. This involved the removal of images with poorly defined labels and efforts to refine labels for increased precision.

The performance of the new model, post-training, exhibited an F1 precision of 72.5%, falling short of expectations. Model testing revealed a precision of 76.5%.

Deployment Challenges and Alternative Approach
Despite efforts to deploy the model into the project, operational challenges persisted. Consequently, a contingency plan was enacted, shifting to the utilization of the Mediapipe "hand model" for hand sign recognition and detection.
