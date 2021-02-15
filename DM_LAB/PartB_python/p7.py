import pandas as pd
from sklearn import preprocessing
import numpy as np
from sklearn.preprocessing import MinMaxScaler
import matplotlib.pyplot as plt
import seaborn as sns
from sklearn.model_selection import train_test_split

df = pd.read_csv('CustomerData.csv')
df = df.bfill()
encoder = preprocessing.LabelEncoder()
df[['category', 'purchase type ', 'gender']] = df[['category', 'purchase type ', 'gender']].apply(encoder.fit_transform)
df.head()

features = df[['age', 'gender', 'annual income (lakhs)']]
target = df['purchase type ']
x_train, x_test, y_train, y_test = train_test_split(features, target, random_state = 0, test_size = 0.3)


from sklearn.cluster import KMeans

dataframe = df[['gender', 'age', 'category']]

kmeans = KMeans(n_clusters = 5, random_state = 0)
kmeans.fit_predict(dataframe)
print("Cluster centers\n", kmeans.cluster_centers_)
dataframe['cluster'] = kmeans.labels_
