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

# features = df[['age', 'gender', 'annual income (lakhs)']]
# target = df['purchase type ']
# x_train, x_test, y_train, y_test = train_test_split(features, target, random_state = 0, test_size = 0.3)

from sklearn.cluster import DBSCAN
df = df[['gender','age','annual income (lakhs)','items purchased (monthly)']]
clustering = DBSCAN(eps=3, min_samples=3).fit(df)
DBSCAN(eps=3, min_samples=2)
 
df['cluster'] = clustering.labels_
df.head()

df['cluster'] = clustering.labels_
df.head()

sns.scatterplot(data = df, x = df.cluster, y = df.gender.replace({0 : "Male", 1 : "Female"}))