"""
Bài thực hành: Mạng Nơ Ron Nhân Tạo (Neural Network)
File: neural_network.py
Mô tả: Xây dựng mạng nơ ron nhiều lớp từ đầu bằng NumPy
"""

import numpy as np


class NeuralNetwork:
    """
    Lớp mạng nơ ron nhân tạo với nhiều lớp ẩn
    Sử dụng thuật toán Backpropagation để huấn luyện
    """
    
    def __init__(self, layer_sizes, learning_rate=0.01):
        """
        Khởi tạo mạng nơ ron
        
        Args:
            layer_sizes: List kích thước các lớp [input_size, hidden1, hidden2, ..., output_size]
            learning_rate: Tốc độ học
        
        Example:
            nn = NeuralNetwork([784, 128, 64, 10], learning_rate=0.01)
        """
        self.layer_sizes = layer_sizes
        self.learning_rate = learning_rate
        self.num_layers = len(layer_sizes)
        
        # Khởi tạo trọng số và bias
        self.weights = []
        self.biases = []
        
        # TODO: Khởi tạo weights và biases cho từng lớp
        # Hint: Sử dụng np.random.randn() với He initialization
        # He initialization: weight = np.random.randn(n_in, n_out) * np.sqrt(2.0 / n_in)
        # Bias có thể khởi tạo bằng 0
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        for i in range(self.num_layers - 1):
            # Khởi tạo weight từ lớp i đến lớp i+1
            pass  # Thay thế dòng này bằng code của bạn
            
            # Khởi tạo bias cho lớp i+1
            pass  # Thay thế dòng này bằng code của bạn
        # ==========================================
        
    def sigmoid(self, z):
        """
        Hàm kích hoạt Sigmoid
        
        Args:
            z: Input
        Returns:
            Giá trị sigmoid(z)
        """
        # TODO: Implement hàm sigmoid
        # Công thức: sigmoid(z) = 1 / (1 + e^(-z))
        # Hint: Sử dụng np.exp()
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        pass  # Thay thế dòng này
        # ==========================================
    
    def sigmoid_derivative(self, z):
        """
        Đạo hàm của hàm sigmoid
        
        Args:
            z: Output của hàm sigmoid
        Returns:
            Đạo hàm sigmoid'(z)
        """
        # TODO: Implement đạo hàm sigmoid
        # Công thức: sigmoid'(z) = sigmoid(z) * (1 - sigmoid(z))
        # Lưu ý: z ở đây đã là output của sigmoid
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        pass  # Thay thế dòng này
        # ==========================================
    
    def relu(self, z):
        """
        Hàm kích hoạt ReLU
        
        Args:
            z: Input
        Returns:
            Giá trị ReLU(z)
        """
        # TODO: Implement hàm ReLU
        # Công thức: ReLU(z) = max(0, z)
        # Hint: Sử dụng np.maximum()
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        pass  # Thay thế dòng này
        # ==========================================
    
    def relu_derivative(self, z):
        """
        Đạo hàm của hàm ReLU
        
        Args:
            z: Input
        Returns:
            Đạo hàm ReLU'(z)
        """
        # TODO: Implement đạo hàm ReLU
        # Công thức: ReLU'(z) = 1 nếu z > 0, ngược lại = 0
        # Hint: Sử dụng z > 0 sẽ trả về boolean array, convert sang int
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        pass  # Thay thế dòng này
        # ==========================================
    
    def softmax(self, z):
        """
        Hàm kích hoạt Softmax (dùng cho lớp output)
        
        Args:
            z: Input matrix (batch_size, num_classes)
        Returns:
            Probability distribution
        """
        # TODO: Implement hàm softmax
        # Công thức: softmax(z_i) = e^(z_i) / sum(e^(z_j))
        # Trick: Trừ max để tránh overflow: softmax(z - max(z))
        # Hint: axis=1 để tính theo từng sample
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        pass  # Thay thế dòng này
        # ==========================================
    
    def forward(self, X):
        """
        Lan truyền tiến (Forward Propagation)
        
        Args:
            X: Input data (batch_size, input_size)
        Returns:
            Output của mạng (batch_size, output_size)
        """
        self.activations = [X]  # Lưu activation của từng lớp
        self.z_values = []      # Lưu giá trị z (trước activation)
        
        # TODO: Implement forward propagation
        # 1. Với mỗi lớp: z = activation @ weight + bias
        # 2. Áp dụng activation function (ReLU cho hidden layers, Softmax cho output)
        # 3. Lưu lại z và activation để dùng cho backpropagation
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        activation = X
        for i in range(self.num_layers - 1):
            # Tính z = a * W + b
            pass  # Thay thế dòng này
            
            # Lưu z
            pass
            
            # Áp dụng activation function
            if i < self.num_layers - 2:  # Hidden layers dùng ReLU
                pass
            else:  # Output layer dùng Softmax
                pass
            
            # Lưu activation
            pass
        
        return activation
        # ==========================================
    
    def backward(self, y_true):
        """
        Lan truyền ngược (Backward Propagation)
        
        Args:
            y_true: Nhãn thực tế (batch_size, output_size) - one-hot encoded
        """
        batch_size = y_true.shape[0]
        
        # Khởi tạo gradients
        d_weights = [np.zeros_like(w) for w in self.weights]
        d_biases = [np.zeros_like(b) for b in self.biases]
        
        # TODO: Implement backward propagation
        # 1. Tính delta cho output layer: delta = y_pred - y_true
        # 2. Tính gradient cho weight và bias của output layer
        # 3. Lan truyền delta ngược về các lớp trước
        # 4. Với mỗi lớp: delta = (delta @ W^T) * activation_derivative
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        
        # Delta cho output layer
        delta = None  # Tính delta = y_pred - y_true
        
        # Lan truyền ngược qua từng lớp
        for i in range(self.num_layers - 2, -1, -1):
            # Tính gradient cho weight và bias
            pass  # d_weights[i] = ...
            pass  # d_biases[i] = ...
            
            # Nếu không phải lớp đầu tiên, tính delta cho lớp trước
            if i > 0:
                # delta = delta @ W^T * activation_derivative
                pass
        
        # ==========================================
        
        # Cập nhật weights và biases
        for i in range(self.num_layers - 1):
            self.weights[i] -= self.learning_rate * d_weights[i]
            self.biases[i] -= self.learning_rate * d_biases[i]
    
    def train_step(self, X_batch, y_batch):
        """
        Thực hiện một bước huấn luyện
        
        Args:
            X_batch: Batch input data
            y_batch: Batch labels (one-hot encoded)
        Returns:
            Loss value
        """
        # Forward pass
        y_pred = self.forward(X_batch)
        
        # Tính loss (Cross-Entropy)
        loss = self.compute_loss(y_pred, y_batch)
        
        # Backward pass
        self.backward(y_batch)
        
        return loss
    
    def compute_loss(self, y_pred, y_true):
        """
        Tính Cross-Entropy Loss
        
        Args:
            y_pred: Predictions (batch_size, num_classes)
            y_true: True labels (batch_size, num_classes)
        Returns:
            Loss value
        """
        # TODO: Implement Cross-Entropy Loss
        # Công thức: L = -1/N * sum(y_true * log(y_pred))
        # Hint: Thêm epsilon nhỏ (1e-8) vào y_pred để tránh log(0)
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        pass  # Thay thế dòng này
        # ==========================================
    
    def predict(self, X):
        """
        Dự đoán nhãn cho dữ liệu
        
        Args:
            X: Input data
        Returns:
            Predicted class indices
        """
        y_pred = self.forward(X)
        return np.argmax(y_pred, axis=1)
    
    def get_params(self):
        """
        Lấy parameters của model
        
        Returns:
            Dictionary chứa weights và biases
        """
        return {
            'weights': self.weights,
            'biases': self.biases,
            'layer_sizes': self.layer_sizes,
            'learning_rate': self.learning_rate
        }
    
    def set_params(self, params):
        """
        Set parameters cho model
        
        Args:
            params: Dictionary chứa weights và biases
        """
        self.weights = params['weights']
        self.biases = params['biases']
        self.layer_sizes = params['layer_sizes']
        self.learning_rate = params['learning_rate']
        self.num_layers = len(self.layer_sizes)
