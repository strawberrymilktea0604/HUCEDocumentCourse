# BÀI THỰC HÀNH: MẠNG NƠ RON NHÂN TẠO (NEURAL NETWORK)

## 📋 THÔNG TIN BÀI THỰC HÀNH

**Mô tả**: Xây dựng mạng nơ ron nhân tạo từ đầu bằng NumPy để phân loại chữ số viết tay MNIST

**Mục tiêu**: 
- Hiểu sâu về cách hoạt động của mạng nơ ron
- Implement forward propagation và backward propagation
- Tự tay tính toán các activation functions và derivatives
- Huấn luyện model và đánh giá hiệu suất

**Yêu cầu**: Sinh viên phải hoàn thành các phần code còn thiếu để mạng nơ ron hoạt động

---

## 🚀 CÀI ĐẶT

### 1. Yêu cầu hệ thống
- Python 3.7 trở lên
- pip hoặc conda

### 2. Cài đặt thư viện

```bash
pip install -r requirements.txt
```

Hoặc cài đặt thủ công:
```bash
pip install numpy matplotlib seaborn
```

---

## 📁 CẤU TRÚC PROJECT

```
Baithuchanh/
│
├── neural_network.py      # Class mạng nơ ron (CẦN HOÀN THÀNH)
├── data_loader.py         # Load và xử lý dữ liệu MNIST (CẦN HOÀN THÀNH)
├── train.py              # Huấn luyện model (CẦN HOÀN THÀNH)
├── inference.py          # Dự đoán với model (CẦN HOÀN THÀNH)
├── evaluation.py         # Đánh giá model (CẦN HOÀN THÀNH)
├── utils.py              # Các hàm tiện ích (ĐÃ HOÀN THÀNH)
├── requirements.txt      # Danh sách thư viện
├── README.md            # Hướng dẫn (file này)
│
├── data/                # Thư mục chứa dữ liệu MNIST (tự động tạo)
├── model.pkl            # Model đã train (tự động tạo)
└── *.png               # Các hình ảnh kết quả (tự động tạo)
```

---

## 📝 NHIỆM VỤ CẦN HOÀN THÀNH

### ⭐ Phần 1: Data Loader (data_loader.py)

**File**: `data_loader.py`

**Các hàm cần hoàn thành**:

1. **`normalize_images()`** (Dòng ~100)
   - Chuẩn hóa giá trị pixel từ [0, 255] về [0, 1]
   - Hint: Chia cho 255.0 và convert sang float32

2. **`flatten_images()`** (Dòng ~113)
   - Chuyển ảnh từ 2D (28x28) sang 1D (784)
   - Hint: Sử dụng `.reshape()`

3. **`one_hot_encode()`** (Dòng ~126)
   - Chuyển nhãn số thành vector one-hot
   - Ví dụ: 3 → [0,0,0,1,0,0,0,0,0,0]
   - Hint: Tạo ma trận zeros, sau đó set 1 ở vị trí tương ứng

4. **`create_mini_batches()`** (Dòng ~180)
   - Chia dữ liệu thành các batch nhỏ
   - Hint: Shuffle trước, sau đó chia theo batch_size

**Cách kiểm tra**:
```bash
python data_loader.py
```

---

### ⭐ Phần 2: Neural Network (neural_network.py)

**File**: `neural_network.py`

**Các hàm cần hoàn thành**:

1. **`__init__()` - Khởi tạo weights và biases** (Dòng ~34)
   - Khởi tạo weights với He initialization
   - Formula: `weight = np.random.randn(n_in, n_out) * np.sqrt(2.0 / n_in)`
   - Bias khởi tạo bằng 0

2. **`sigmoid()`** (Dòng ~48)
   - Công thức: `σ(z) = 1 / (1 + e^(-z))`
   - Hint: Dùng `np.exp()`

3. **`sigmoid_derivative()`** (Dòng ~60)
   - Công thức: `σ'(z) = σ(z) * (1 - σ(z))`

4. **`relu()`** (Dòng ~72)
   - Công thức: `ReLU(z) = max(0, z)`
   - Hint: Dùng `np.maximum(0, z)`

5. **`relu_derivative()`** (Dòng ~84)
   - Công thức: `ReLU'(z) = 1 nếu z > 0, ngược lại 0`
   - Hint: `(z > 0).astype(float)`

6. **`softmax()`** (Dòng ~96)
   - Công thức: `softmax(z_i) = e^(z_i) / Σ(e^(z_j))`
   - **Quan trọng**: Trừ max(z) để tránh overflow
   - Hint: axis=1 để tính theo từng sample

7. **`forward()`** (Dòng ~110)
   - Lan truyền tiến qua mạng
   - Với mỗi lớp: `z = activation @ weight + bias`
   - Hidden layers: dùng ReLU
   - Output layer: dùng Softmax
   - **Lưu ý**: Phải lưu lại `z_values` và `activations` cho backward

8. **`backward()`** (Dòng ~143)
   - Lan truyền ngược để tính gradients
   - Output layer: `delta = y_pred - y_true`
   - Hidden layers: `delta = (delta @ W^T) * activation_derivative`
   - Tính gradients: `dW = a^T @ delta`, `db = sum(delta)`

9. **`compute_loss()`** (Dòng ~183)
   - Cross-Entropy Loss: `L = -1/N * Σ(y_true * log(y_pred))`
   - **Quan trọng**: Thêm epsilon (1e-8) để tránh log(0)

**Công thức quan trọng**:

```
Forward Propagation:
  z[l] = a[l-1] @ W[l] + b[l]
  a[l] = activation(z[l])

Backward Propagation:
  δ[L] = a[L] - y_true              (output layer)
  δ[l] = (δ[l+1] @ W[l+1]^T) ⊙ f'(z[l])  (hidden layers)
  
  dW[l] = a[l-1]^T @ δ[l] / batch_size
  db[l] = sum(δ[l], axis=0) / batch_size
```

---

### ⭐ Phần 3: Training (train.py)

**File**: `train.py`

**Hàm cần hoàn thành**: `train_model()` (Dòng ~28) và `main()` (Dòng ~80)

**Nhiệm vụ trong `train_model()`**:
1. Chia dữ liệu thành mini-batches
2. Với mỗi batch:
   - Gọi `model.train_step()` để train
   - Lưu loss
3. Tính average loss cho epoch
4. Tính accuracy trên tập train và validation
5. Lưu history và in kết quả

**Nhiệm vụ trong `main()`**:
1. Load dữ liệu MNIST
2. Chia train/validation (80-20)
3. Khởi tạo model với kiến trúc phù hợp
   - Gợi ý: [784, 128, 64, 10]
   - Learning rate: 0.01 hoặc 0.1
4. Gọi `train_model()` để huấn luyện
5. Lưu model và vẽ biểu đồ

**Cách chạy**:
```bash
python train.py
```

**Output mong đợi**:
- File `model.pkl`: Model đã train
- File `training_history.png`: Biểu đồ loss và accuracy

**Thời gian chạy**: ~5-10 phút với 20 epochs

---

### ⭐ Phần 4: Inference (inference.py)

**File**: `inference.py`

**Các hàm cần hoàn thành**:

1. **`predict_single_image()`** (Dòng ~20)
   - Dự đoán cho một ảnh
   - Reshape ảnh về (1, 784) nếu cần
   - Forward pass để lấy probabilities
   - Lấy class có xác suất cao nhất

2. **`predict_batch()`** (Dòng ~55)
   - Dự đoán cho nhiều ảnh cùng lúc
   - Tính accuracy nếu có true labels

3. **`main()`** (Dòng ~160)
   - Load model đã train
   - Load test data
   - Dự đoán trên test set
   - Hiển thị kết quả và visualization

**Cách chạy**:
```bash
python inference.py
```

**Output mong đợi**:
- Test accuracy
- File `predictions_visualization.png`: Hiển thị dự đoán
- (Optional) Chế độ tương tác để thử từng ảnh

---

### ⭐ Phần 5: Evaluation (evaluation.py)

**File**: `evaluation.py`

**Các hàm cần hoàn thành**:

1. **`calculate_accuracy()`** (Dòng ~15)
   - Công thức: `Accuracy = (Số dự đoán đúng) / (Tổng số mẫu)`

2. **`calculate_precision_recall_f1()`** (Dòng ~28)
   - Với mỗi class, tính:
     - TP (True Positive): Dự đoán đúng
     - FP (False Positive): Dự đoán sai là class này
     - FN (False Negative): Thực tế là class này nhưng dự đoán sai
   - Công thức:
     - `Precision = TP / (TP + FP)`
     - `Recall = TP / (TP + FN)`
     - `F1 = 2 * (Precision * Recall) / (Precision + Recall)`

3. **`calculate_confusion_matrix()`** (Dòng ~79)
   - Ma trận confusion: `cm[i][j]` = số mẫu có nhãn thực i được dự đoán là j
   - Hint: Lặp qua từng mẫu hoặc dùng numpy indexing

4. **`evaluate_model()`** (Dòng ~120)
   - Gọi các hàm trên để tính toàn bộ metrics
   - Vẽ confusion matrix và biểu đồ metrics

**Cách chạy**:
```bash
python evaluation.py
```

**Output mong đợi**:
- Accuracy tổng thể
- Precision, Recall, F1 cho từng class (0-9)
- File `confusion_matrix.png`: Ma trận confusion
- File `metrics_per_class.png`: Biểu đồ metrics
- File `error_analysis.png`: Phân tích các dự đoán sai

---

## 🔧 HƯỚNG DẪN THỰC HIỆN CHI TIẾT

### Bước 1: Hiểu cấu trúc dữ liệu

```python
# MNIST Dataset:
# - Training: 60,000 ảnh chữ số viết tay (0-9)
# - Test: 10,000 ảnh
# - Kích thước: 28x28 pixels
# - Giá trị pixel: 0-255 (grayscale)

# Sau khi xử lý:
# - X_train: (60000, 784) - flatten và normalize
# - y_train: (60000, 10) - one-hot encoded
# - X_test: (10000, 784)
# - y_test: (10000, 10)
```

### Bước 2: Hiểu kiến trúc mạng

```
Input Layer (784) 
    ↓ [W1: 784×128, b1: 128]
Hidden Layer 1 (128) + ReLU
    ↓ [W2: 128×64, b2: 64]
Hidden Layer 2 (64) + ReLU
    ↓ [W3: 64×10, b3: 10]
Output Layer (10) + Softmax
```

### Bước 3: Quy trình hoàn chỉnh

```
1. Load và xử lý dữ liệu (data_loader.py)
   ↓
2. Khởi tạo mạng nơ ron (neural_network.py)
   ↓
3. Training Loop (train.py):
   - Forward pass → Tính loss
   - Backward pass → Tính gradients
   - Update weights
   - Lặp lại với batch tiếp theo
   ↓
4. Lưu model
   ↓
5. Inference: Load model và dự đoán (inference.py)
   ↓
6. Evaluation: Đánh giá chi tiết (evaluation.py)
```

### Bước 4: Debug và kiểm tra

**Các điểm cần kiểm tra**:

1. **Shape của tensors**:
   ```python
   print(f"X shape: {X.shape}")  # (batch_size, 784)
   print(f"W shape: {W.shape}")  # (784, 128)
   print(f"Output shape: {output.shape}")  # (batch_size, 128)
   ```

2. **Loss giảm dần**:
   - Epoch đầu: Loss cao (>2.0)
   - Sau vài epoch: Loss giảm xuống (~0.5-1.0)
   - Nếu loss không giảm → Kiểm tra backward pass

3. **Accuracy tăng dần**:
   - Epoch đầu: ~10% (random guess)
   - Sau vài epoch: >80%
   - Kết thúc: >90%

4. **Gradients không bị vanishing/exploding**:
   - Kiểm tra norm của weights
   - Nếu quá nhỏ (<1e-5) → Vanishing
   - Nếu quá lớn (>100) → Exploding

---

## 📊 KẾT QUẢ MONG ĐỢI

### Hiệu suất tối thiểu:
- **Training Accuracy**: ≥ 95%
- **Test Accuracy**: ≥ 90%
- **Training time**: 5-10 phút (20 epochs)

### Hiệu suất tốt:
- **Training Accuracy**: ≥ 98%
- **Test Accuracy**: ≥ 95%
- **Per-class F1-score**: ≥ 0.90 cho tất cả các class

---

## 🐛 TROUBLESHOOTING

### Lỗi thường gặp:

1. **Loss = NaN hoặc Inf**
   - Nguyên nhân: Overflow trong softmax hoặc log(0)
   - Giải pháp: 
     - Softmax: Trừ max trước khi exp
     - Log: Thêm epsilon (1e-8)

2. **Accuracy không tăng (застряло ở ~10%)**
   - Nguyên nhân: Backward pass sai
   - Giải pháp: Kiểm tra lại công thức tính gradient

3. **Loss giảm quá chậm**
   - Nguyên nhân: Learning rate quá nhỏ
   - Giải pháp: Tăng learning rate (thử 0.1 thay vì 0.01)

4. **Loss dao động mạnh**
   - Nguyên nhân: Learning rate quá lớn
   - Giải pháp: Giảm learning rate hoặc tăng batch size

5. **Runtime Error: shapes not aligned**
   - Nguyên nhân: Nhầm lẫn về matrix dimensions
   - Giải pháp: 
     - Kiểm tra shape của tensors
     - Forward: `a @ W` (not `W @ a`)
     - Backward: Nhớ transpose

---

## 💡 GỢI Ý VÀ TIPS

### Tips cho Forward Propagation:
```python
# Đừng quên lưu z và activation
self.z_values.append(z)
self.activations.append(activation)

# Softmax trick để tránh overflow
exp_scores = np.exp(z - np.max(z, axis=1, keepdims=True))
probs = exp_scores / np.sum(exp_scores, axis=1, keepdims=True)
```

### Tips cho Backward Propagation:
```python
# Delta cho output layer (với softmax + cross-entropy)
delta = y_pred - y_true  # Đơn giản vậy thôi!

# Delta cho hidden layer
delta = np.dot(delta, self.weights[i+1].T) * self.relu_derivative(self.z_values[i])

# Gradient
dW = np.dot(self.activations[i].T, delta) / batch_size
db = np.sum(delta, axis=0, keepdims=True) / batch_size
```

### Tips cho Mini-batch:
```python
# Shuffle dữ liệu
indices = np.random.permutation(len(X))
X_shuffled = X[indices]
y_shuffled = y[indices]

# Chia batch
for i in range(0, len(X), batch_size):
    X_batch = X_shuffled[i:i+batch_size]
    y_batch = y_shuffled[i:i+batch_size]
```

### Tips cho Metrics:
```python
# Confusion matrix
for i in range(len(y_true)):
    cm[y_true[i]][y_pred[i]] += 1

# Hoặc dùng numpy (nâng cao)
for true_label, pred_label in zip(y_true, y_pred):
    cm[true_label, pred_label] += 1
```

---

## 📚 TÀI LIỆU THAM KHẢO

### Lý thuyết cơ bản:
- Activation functions: Sigmoid, ReLU, Softmax
- Loss function: Cross-Entropy
- Optimization: Stochastic Gradient Descent (SGD)
- Backpropagation algorithm

### Công thức toán học quan trọng:

**1. Forward Pass:**
$$z^{[l]} = a^{[l-1]} W^{[l]} + b^{[l]}$$
$$a^{[l]} = g^{[l]}(z^{[l]})$$

**2. Loss Function (Cross-Entropy):**
$$L = -\frac{1}{N} \sum_{i=1}^{N} \sum_{j=1}^{C} y_{ij} \log(\hat{y}_{ij})$$

**3. Backward Pass:**
$$\delta^{[L]} = \hat{y} - y$$
$$\delta^{[l]} = (\delta^{[l+1]} \cdot W^{[l+1]T}) \odot g'^{[l]}(z^{[l]})$$
$$\frac{\partial L}{\partial W^{[l]}} = \frac{1}{m} a^{[l-1]T} \cdot \delta^{[l]}$$
$$\frac{\partial L}{\partial b^{[l]}} = \frac{1}{m} \sum_{i=1}^{m} \delta^{[l]}_i$$

**4. Update:**
$$W^{[l]} := W^{[l]} - \alpha \frac{\partial L}{\partial W^{[l]}}$$
$$b^{[l]} := b^{[l]} - \alpha \frac{\partial L}{\partial b^{[l]}}$$

---

## ✅ CHECKLIST HOÀN THÀNH

### Checklist cho sinh viên:

- [ ] **Data Loader**
  - [ ] normalize_images()
  - [ ] flatten_images()
  - [ ] one_hot_encode()
  - [ ] create_mini_batches()
  - [ ] Test: `python data_loader.py` chạy thành công

- [ ] **Neural Network**
  - [ ] Khởi tạo weights/biases
  - [ ] sigmoid() và sigmoid_derivative()
  - [ ] relu() và relu_derivative()
  - [ ] softmax()
  - [ ] forward()
  - [ ] backward()
  - [ ] compute_loss()

- [ ] **Training**
  - [ ] Implement training loop
  - [ ] Chia train/validation
  - [ ] Lưu model và history
  - [ ] Test: `python train.py` chạy thành công
  - [ ] Kiểm tra: loss giảm, accuracy tăng

- [ ] **Inference**
  - [ ] predict_single_image()
  - [ ] predict_batch()
  - [ ] Load model và dự đoán
  - [ ] Test: `python inference.py` chạy thành công

- [ ] **Evaluation**
  - [ ] calculate_accuracy()
  - [ ] calculate_precision_recall_f1()
  - [ ] calculate_confusion_matrix()
  - [ ] Vẽ các biểu đồ
  - [ ] Test: `python evaluation.py` chạy thành công

- [ ] **Kết quả đạt yêu cầu**
  - [ ] Test Accuracy ≥ 90%
  - [ ] Có file model.pkl
  - [ ] Có các file ảnh kết quả (.png)

---

## 🎯 BÀI TẬP NÂNG CAO (OPTIONAL)

Sau khi hoàn thành cơ bản, sinh viên có thể thử:

1. **Thêm Momentum vào SGD**
   - Công thức: `v = β*v + (1-β)*gradient`
   - Update: `weight -= learning_rate * v`

2. **Implement Learning Rate Decay**
   - Giảm learning rate theo epochs
   - Ví dụ: `lr = initial_lr * (0.95 ** (epoch // 5))`

3. **Thêm Dropout để tránh overfitting**
   - Randomly "tắt" một số neurons trong training
   - Dropout rate: 0.2-0.5

4. **Thử các kiến trúc khác**
   - Thêm/bớt hidden layers
   - Thay đổi số neurons
   - So sánh kết quả

5. **Implement Batch Normalization**
   - Normalize activations giữa các layers

6. **Thử các activation functions khác**
   - Leaky ReLU: `max(0.01*z, z)`
   - tanh: `(e^z - e^(-z)) / (e^z + e^(-z))`

---

## 📞 HỖ TRỢ

Nếu gặp khó khăn, sinh viên có thể:
1. Đọc kỹ các comment và hint trong code
2. Kiểm tra lại công thức toán học
3. Debug bằng cách print shape và giá trị của tensors
4. Tham khảo phần Troubleshooting
5. Hỏi giảng viên/trợ giảng

---

## 📝 NỘP BÀI

**Yêu cầu nộp bài**:
1. Toàn bộ source code đã hoàn thành
2. File `model.pkl` (model đã train)
3. Các file ảnh kết quả (training_history.png, confusion_matrix.png, etc.)
4. File báo cáo (nếu yêu cầu) bao gồm:
   - Kiến trúc mạng đã chọn
   - Hyperparameters (learning rate, batch size, epochs)
   - Kết quả đạt được (accuracy, precision, recall, F1)
   - Phân tích và nhận xét

**Tiêu chí đánh giá**:
- Code chạy đúng và đầy đủ: 60%
- Kết quả đạt yêu cầu (accuracy ≥ 90%): 20%
- Code sạch, có comment: 10%
- Báo cáo và phân tích: 10%

---

## 🎓 KẾT LUẬN

Bài thực hành này giúp sinh viên:
- ✅ Hiểu sâu về cách hoạt động của Neural Network
- ✅ Thực hành implement các thuật toán từ đầu
- ✅ Làm quen với NumPy và các thao tác ma trận
- ✅ Học cách debug và tối ưu model
- ✅ Hiểu rõ các metrics đánh giá model

**Chúc các bạn thành công! 🚀**

---

*Tài liệu được tạo cho môn học Mạng Nơ Ron Nhân Tạo*  
*Cập nhật lần cuối: December 2025*
