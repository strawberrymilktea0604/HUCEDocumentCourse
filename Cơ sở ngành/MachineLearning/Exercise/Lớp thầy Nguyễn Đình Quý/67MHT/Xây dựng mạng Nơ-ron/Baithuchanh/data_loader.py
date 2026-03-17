"""
Bài thực hành: Mạng Nơ Ron Nhân Tạo (Neural Network)
File: data_loader.py
Mô tả: Tải và xử lý dữ liệu MNIST
"""

import numpy as np
import gzip
import os
from urllib import request


class MNISTLoader:
    """
    Lớp để tải và xử lý dữ liệu MNIST
    """
    
    def __init__(self, data_dir='./data'):
        """
        Khởi tạo data loader
        
        Args:
            data_dir: Thư mục chứa dữ liệu MNIST
        """
        self.data_dir = data_dir
        self.base_url = 'http://yann.lecun.com/exdb/mnist/'
        
        # Tạo thư mục data nếu chưa có
        if not os.path.exists(data_dir):
            os.makedirs(data_dir)
        
        # Tên các file MNIST
        self.files = {
            'train_images': 'train-images-idx3-ubyte.gz',
            'train_labels': 'train-labels-idx1-ubyte.gz',
            'test_images': 't10k-images-idx3-ubyte.gz',
            'test_labels': 't10k-labels-idx1-ubyte.gz'
        }
    
    def download_mnist(self):
        """
        Tải dữ liệu MNIST từ internet nếu chưa có
        """
        print("Đang kiểm tra và tải dữ liệu MNIST...")
        
        for key, filename in self.files.items():
            filepath = os.path.join(self.data_dir, filename)
            
            if not os.path.exists(filepath):
                print(f"Đang tải {filename}...")
                url = self.base_url + filename
                request.urlretrieve(url, filepath)
                print(f"Đã tải xong {filename}")
            else:
                print(f"{filename} đã tồn tại")
    
    def load_images(self, filename):
        """
        Đọc file ảnh MNIST
        
        Args:
            filename: Tên file ảnh
        Returns:
            numpy array chứa ảnh (num_images, 28, 28)
        """
        filepath = os.path.join(self.data_dir, filename)
        
        with gzip.open(filepath, 'rb') as f:
            # Đọc magic number và metadata
            magic = int.from_bytes(f.read(4), 'big')
            num_images = int.from_bytes(f.read(4), 'big')
            rows = int.from_bytes(f.read(4), 'big')
            cols = int.from_bytes(f.read(4), 'big')
            
            # Đọc dữ liệu ảnh
            data = np.frombuffer(f.read(), dtype=np.uint8)
            data = data.reshape(num_images, rows, cols)
            
        return data
    
    def load_labels(self, filename):
        """
        Đọc file nhãn MNIST
        
        Args:
            filename: Tên file nhãn
        Returns:
            numpy array chứa nhãn (num_labels,)
        """
        filepath = os.path.join(self.data_dir, filename)
        
        with gzip.open(filepath, 'rb') as f:
            # Đọc magic number và metadata
            magic = int.from_bytes(f.read(4), 'big')
            num_labels = int.from_bytes(f.read(4), 'big')
            
            # Đọc dữ liệu nhãn
            data = np.frombuffer(f.read(), dtype=np.uint8)
            
        return data
    
    def normalize_images(self, images):
        """
        Chuẩn hóa ảnh về khoảng [0, 1]
        
        Args:
            images: Ảnh dạng uint8 (0-255)
        Returns:
            Ảnh chuẩn hóa về float32 (0-1)
        """
        # TODO: Normalize ảnh về [0, 1]
        # Hint: Chia cho 255.0 và chuyển sang float32
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        pass  # Thay thế dòng này
        # ==========================================
    
    def flatten_images(self, images):
        """
        Chuyển ảnh từ 2D (28x28) sang 1D (784)
        
        Args:
            images: Ảnh shape (num_images, 28, 28)
        Returns:
            Ảnh flatten shape (num_images, 784)
        """
        # TODO: Flatten ảnh từ (n, 28, 28) -> (n, 784)
        # Hint: Sử dụng reshape(-1, 784) hoặc reshape(images.shape[0], -1)
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        pass  # Thay thế dòng này
        # ==========================================
    
    def one_hot_encode(self, labels, num_classes=10):
        """
        Chuyển đổi nhãn sang dạng one-hot encoding
        
        Args:
            labels: Nhãn dạng số (0-9)
            num_classes: Số lượng class
        Returns:
            One-hot encoded labels (num_labels, num_classes)
        
        Example:
            Input: [2, 0, 3]
            Output: [[0,0,1,0,0,0,0,0,0,0],
                     [1,0,0,0,0,0,0,0,0,0],
                     [0,0,0,1,0,0,0,0,0,0]]
        """
        # TODO: Implement one-hot encoding
        # Hint: Tạo ma trận zeros (len(labels), num_classes)
        # Sau đó set giá trị 1 ở vị trí tương ứng
        # Có thể dùng: one_hot[np.arange(len(labels)), labels] = 1
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        pass  # Thay thế dòng này
        # ==========================================
    
    def load_data(self):
        """
        Tải toàn bộ dữ liệu MNIST
        
        Returns:
            (X_train, y_train, X_test, y_test)
            - X_train: Training images (60000, 784)
            - y_train: Training labels (60000, 10) - one-hot encoded
            - X_test: Test images (10000, 784)
            - y_test: Test labels (10000, 10) - one-hot encoded
        """
        # Tải dữ liệu nếu chưa có
        self.download_mnist()
        
        print("\nĐang tải dữ liệu MNIST...")
        
        # Load train data
        train_images = self.load_images(self.files['train_images'])
        train_labels = self.load_labels(self.files['train_labels'])
        
        # Load test data
        test_images = self.load_images(self.files['test_images'])
        test_labels = self.load_labels(self.files['test_labels'])
        
        print(f"Train images: {train_images.shape}")
        print(f"Train labels: {train_labels.shape}")
        print(f"Test images: {test_images.shape}")
        print(f"Test labels: {test_labels.shape}")
        
        # Preprocessing
        print("\nĐang xử lý dữ liệu...")
        
        # Normalize và flatten images
        X_train = self.flatten_images(self.normalize_images(train_images))
        X_test = self.flatten_images(self.normalize_images(test_images))
        
        # One-hot encode labels
        y_train = self.one_hot_encode(train_labels)
        y_test = self.one_hot_encode(test_labels)
        
        print(f"X_train shape: {X_train.shape}")
        print(f"y_train shape: {y_train.shape}")
        print(f"X_test shape: {X_test.shape}")
        print(f"y_test shape: {y_test.shape}")
        
        return X_train, y_train, X_test, y_test
    
    def create_mini_batches(self, X, y, batch_size):
        """
        Chia dữ liệu thành các mini-batch
        
        Args:
            X: Input data
            y: Labels
            batch_size: Kích thước batch
        Returns:
            List of (X_batch, y_batch) tuples
        """
        # TODO: Chia dữ liệu thành mini-batches
        # Hint: 
        # 1. Shuffle indices
        # 2. Chia thành các batch có kích thước batch_size
        # 3. Batch cuối cùng có thể nhỏ hơn batch_size
        
        # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
        mini_batches = []
        
        # Shuffle data
        pass  # Tạo random permutation của indices
        
        # Chia thành batches
        pass  # Lặp qua data và tạo các batch
        
        return mini_batches
        # ==========================================


# Test code
if __name__ == "__main__":
    loader = MNISTLoader()
    X_train, y_train, X_test, y_test = loader.load_data()
    
    print("\n=== Kiểm tra dữ liệu ===")
    print(f"Training set: {X_train.shape[0]} samples")
    print(f"Test set: {X_test.shape[0]} samples")
    print(f"Input size: {X_train.shape[1]}")
    print(f"Number of classes: {y_train.shape[1]}")
    print(f"\nMẫu nhãn đầu tiên: {y_train[0]}")
    print(f"Class của mẫu đầu tiên: {np.argmax(y_train[0])}")
