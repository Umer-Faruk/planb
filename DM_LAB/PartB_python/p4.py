import pandas as pd
from sklearn import preprocessing
import numpy as np
from sklearn.preprocessing import MinMaxScaler
import matplotlib.pyplot as plt
import seaborn as sns

df1 = pd.read_csv('CustomerData.csv')
df1 = df1.bfill()

# !pip install pyfpgrowth
import pyfpgrowth as fpg
records = []

for i in range(len(df1)):
    record = []
    for j in range(len(df1.columns)):
        if df1.values[i, j]:
            record.append(df1.columns[j])
    records.append(record)

itemsets = fpg.find_frequent_patterns(records, 0.03)


itemsets

fpg.generate_association_rules(itemsets, 0.7)