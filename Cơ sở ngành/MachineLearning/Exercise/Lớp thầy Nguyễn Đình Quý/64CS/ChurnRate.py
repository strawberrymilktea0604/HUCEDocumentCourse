# Import libraries
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn import preprocessing
from sklearn.tree import DecisionTreeClassifier
from sklearn.metrics import classification_report
from xgboost import XGBClassifier
from imblearn.over_sampling import SMOTE

# Read Data
df = pd.read_csv("./content/churn-bigml-80.csv")
df_test = pd.read_csv("./content/churn-bigml-20.csv")

# Exploratory Data Analysis
# 1. Trường 'Churn' là trường mục tiêu, cho biết khách hàng rời bỏ hay vẫn sử dụng dịch vụ.
# 2. Các trường còn lại sẽ xoay quanh trường 'Churn' để phân tích, đưa ra quyết định xem khách có ý định tiếp tục hay bỏ dịch vụ.
# 3. Mục tiêu bài toán, xác định, dự đoán các khách hàng có ý định rời bỏ dịch vụ ('Churn' == True) là cấp thiết. Để đưa ra các giải pháp, chiến lược phù hợp nhằm giữ chân khách hàng.

labels = 'Exited', 'Retained'
sizes = [df.Churn[df['Churn']==True].count(), df.Churn[df['Churn']==False].count()]
explode = (0, 0.1)
fig1, ax1 = plt.subplots(figsize=(8, 6))
ax1.pie(sizes, explode=explode, labels=labels, autopct='%1.1f%%',
        shadow=True, startangle=90)
ax1.axis('equal')
plt.title("Proportion of customer churned and retained", size = 20)
plt.show()

# Có thể thấy khoảng 14.6% khách hàng đã rời bỏ. Vì vậy, cần xây dựng mô hình có
# thể dự đoán 14.6% khách hàng sẽ rời bỏ. Với dữ liệu có số nhãn khách hàng rời bỏ chỉ chiếm 14.6%, rất nhỏ trong tập dữ liệu. Vì vậy cần đảm bảo rằng mô hình được chọn dự đoán với độ chính xác cao những khách hàng rời bỏ này.

sns.countplot(x="Customer service calls", hue="Churn", data=df)

# Có thể thấy tỷ lệ rời bỏ khách hàng ngày càng tăng khi số lượng cuộc gọi dịch vụ khách hàng được thực hiện bởi khách hàng ngày càng tăng.
# -> Có vấn đề về chuất lượng dịch vụ? Hay chăm sóc khách hàng?

_, axes = plt.subplots(1, 2, sharey=True, figsize=(10, 4))

sns.countplot(x="International plan", hue="Churn", data=df, ax=axes[0])
sns.countplot(x="Voice mail plan", hue="Churn", data=df, ax=axes[1])

# 1.   Số lượng người đăng ký 'International plan' rời bỏ dịch vụ khá nhiều. -> Khách hàng không hài lòng?
# 2.   Số lượng người đăng ký 'Voice mail plan' rời bỏ dịch vụ khá ít -> Dịch vụ tiện ích hoặc đảm bảo giữ chân khách hàng và khách hàng không đăng ký thì rời bỏ nhiều. -> Có thể đưa ra một số lợi ích để khách hàng đăng ký dịch vụ.

sns.boxplot(x="Churn", y="Account length", data=df)
# Trong khoảng từ 75 đến 100 có tỷ lệ khách hàng rời bỏ tập trung nhiều.

# Buid Model
label_encoder = preprocessing.LabelEncoder()
# Chuẩn hóa dữ liệu về dạng số của một số trường
label_encoder = preprocessing.LabelEncoder()

# Data train
df['State'] = label_encoder.fit_transform(df['State'])
df['International plan'] = label_encoder.fit_transform(df['International plan'])
df['Voice mail plan'] = label_encoder.fit_transform(df['Voice mail plan'])
df['Churn'] = label_encoder.fit_transform(df['Churn'])

# Data test
df_test['State'] = label_encoder.fit_transform(df_test['State'])
df_test['International plan'] = label_encoder.fit_transform(df_test['International plan'])
df_test['Voice mail plan'] = label_encoder.fit_transform(df_test['Voice mail plan'])
df_test['Churn'] = label_encoder.fit_transform(df_test['Churn'])

# Train
X_train = df.drop(['Churn'], axis=1)
y_train = df.Churn

# Test
X_test = df_test.drop(['Churn'], axis=1)
y_test = df_test.Churn

# Balance data
print("Before OverSampling, counts of label '1': {}".format(sum(y_train==1)))
print("Before OverSampling, counts of label '0': {} \n".format(sum(y_train==0)))

sm = SMOTE(random_state=2)
X_train_smote, y_train_smote = sm.fit_resample(X_train, y_train)

print("After OverSampling, counts of label '1': {}".format(sum(y_train_smote==1)))
print("After OverSampling, counts of label '0': {}".format(sum(y_train_smote==0)))

# Decision Tree
tree = DecisionTreeClassifier(max_depth=6, random_state=17)
tree.fit(X_train, y_train)
y_pred = tree.predict(X_test)
print(classification_report(y_test, y_pred))

# XGBoost
clf = XGBClassifier(max_depth=7, n_estimators=200, colsample_bytree=0.8,
    subsample=0.8, nthread=10, learning_rate=0.1)
clf.fit(X_train, y_train)
y_pred = clf.predict(X_test)
print(classification_report(y_test, y_pred))

tree = DecisionTreeClassifier(max_depth=6, random_state=17)
tree.fit(X_train_smote, y_train_smote)
y_pred = tree.predict(X_test)
print(classification_report(y_test, y_pred))

clf = XGBClassifier(max_depth=7, n_estimators=200, colsample_bytree=0.8,
    subsample=0.8, nthread=10, learning_rate=0.1)
clf.fit(X_train_smote, y_train_smote)
y_pred = clf.predict(X_test)
print(classification_report(y_test, y_pred))

# 1. Độ chính xác khi dự đoán nhãn 1 cũng khá cao
# 2. Dữ liệu khi SMOTE có độ chính xác khá thấp khi xử lý over-sampling, có thể xử lý bằng cách khác như under-sampling.
# 3. Có một số trường có thể đi trực quan để hiểu rõ thêm về dữ liệu.
# 4. Sử dụng thêm ma trận tương quan để đi đánh giá các trường và loại bỏ bớt các trường không liên quan.
# 5. Lựa chọn các mô hình khác để huấn luyện, cũng như điều chỉnh tham số cảu mô hình để tối ưu mô hình dự đoán.
# 6. Kiểm tra các trường quan trọng sau khi huấn luyện mô hình tốt.
