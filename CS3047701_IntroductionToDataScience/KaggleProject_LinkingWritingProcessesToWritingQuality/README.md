# Linking Writing Processes to Writing Quality

## Project Overview
Hosted by Vanderbilt University in collaboration with The Learning Agency Lab, this competition aims to leverage process features from keystroke logs to predict overall writing quality and uncover connections between learners' writing behaviors and their performance. Participants are tasked with developing a predictive model using a substantial dataset of keystroke logs, providing insights into the potential impact of typing behavior on essay outcomes.

## Dataset Description

The competition dataset consists of logs from approximately 5000 user inputs, including keystrokes and mouse clicks during essay composition. Each essay is scored on a scale from 0 to 6. The dataset includes the following files:

1. **train_logs.csv**: Contains user input logs during essay composition, including event details, actions, and other relevant information.
2. **train_scores.csv**: Provides essay scores, which serve as the target variable for the prediction task.
3. **test_logs.csv**: Similar to `train_logs.csv`, but used for making predictions on unseen data. The public version includes only example logs to illustrate the format.

## Expected Analysis

The analysis plan involves:

1. **Understanding the Dataset**: Explore the `train_logs.csv` to understand its features and address any data quality issues.
2. **Modeling**: Experiment with various regression models such as linear regression, decision trees, and gradient boosting to predict essay scores.
3. **Validation and Tuning**: Train, validate, and fine-tune the chosen model for optimal performance.
4. **Testing**: Predict essay scores on the `test_logs.csv` dataset, focusing on creating a well-generalizing model.
5. **Evaluation**: Use Root Mean Squared Error (RMSE) as the evaluation metric for submitted models in this competition.

## Application of Analysis Results

The insights gained from this analysis can help:

- Explore the relationship between learners’ writing behaviors and writing performance.
- Develop automated writing evaluation techniques and intelligent tutoring systems.
- Improve writing instruction by understanding how typing behavior affects essay quality.

## Reference

Franklin, A., King, J., Demkin, M., Bafour, P., Holbrook, R., & Crossley, S. (2023). [Linking Writing Processes to Writing Quality](https://www.kaggle.com/competitions/linking-writing-processes-to-writing-quality). Kaggle.

## Other Team Members

* Valencia Lo 羅翡瑩 @rasperberrypie
* Veronica Lukita 盧清珍 @stiyqr
* Christopher 余忠信