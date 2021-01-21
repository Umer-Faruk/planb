import pandas as pd
import numpy as np
import seaborn as sns
import sklearn
import matplotlib.pyplot as plt

transaction_data = pd.read_csv('association_analysis.csv')
transaction_data.head()
transaction_data.drop(columns=['tid'],axis=1,inplace=True)


records = []
for i in range(len(transaction_data)):
    record = []
    for j in range(len(transaction_data.columns)):
        if transaction_data.values[i,j]:
            record.append(transaction_data.columns[j])
    records.append(record)

records

# !pip install apyori
from apyori import apriori
rules = apriori(records, min_support = 0.03, min_confidence = 0.7)
rules = list(rules)
for rule in rules:
    print("Rule : ", rule[0], "Support :", rule[1], "Confidence : ", rule[2][0][2])


# !pip install pyfpgrowth

import pyfpgrowth
itemsets = pyfpgrowth.find_frequent_patterns(records, 0.03)

itemsets
pyfpgrowth.generate_association_rules(itemsets, 0.7)


data = pd.read_csv('CustomerData.csv')

from sklearn.model_selection import train_test_split
features = data[['gender','annual income (lakhs)']]
target = data['purchase type ']
x_train, x_test, y_train, y_test = train_test_split(features, target, random_state=0, test_size = 0.3)

from sklearn.tree import DecisionTreeClassifier

model =  DecisionTreeClassifier()
model.fit(x_train, y_train)
pred = model.predict(x_test)
model.score(x_test, y_test)


from sklearn import metrics
metrics.confusion_matrix(y_test, pred)
metrics.classification_report(y_test, pred)

roc = metrics.roc_curve(y_test,pred)
sns.lineplot(x=roc[0],y=roc[1])

from sklearn.ensemble import BaggingClassifier
bag = BaggingClassifier()
bag.fit(x_train,y_train)
pred = bag.predict(x_test)
metrics.confusion_matrix(y_test,pred)
metrics.classification_report(y_test,pred)
roc = metrics.roc_curve(y_test,pred)
sns.lineplot(x=roc[0], y=roc[1])


from sklearn.ensemble import AdaBoostClassifier

boost = AdaBoostClassifier()
boost.fit(x_train, y_train)
pred = boost.predict(x_test)
metrics.confusion_matrix(pred,y_test)
metrics.classification_report(pred,y_test)
roc = metrics.roc_curve(pred,y_test)
sns.lineplot(x=roc[0],y=roc[1])






from sklearn.cluster import KMeans

kmeans = KMeans(n_clusters=2, random_state=0)
kmeans.fit(x_train, y_train)
pred = kmeans.predict(x_test)
metrics.confusion_matrix(pred,y_test)
metrics.classification_report(pred,y_test)
roc = metrics.roc_curve(y_test,pred)
sns.lineplot(x=roc[0],y=roc[1])