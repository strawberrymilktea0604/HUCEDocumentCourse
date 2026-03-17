"""
Bài thực hành: Mạng Nơ Ron Nhân Tạo (Neural Network)
File: train.py
Mô tả: Huấn luyện mạng nơ ron với dữ liệu MNIST
"""

import numpy as np
import time
from neural_network import NeuralNetwork
from data_loader import MNISTLoader
from utils import save_model, plot_training_history


def train_model(model, X_train, y_train, X_val, y_val, 
                epochs=10, batch_size=32, verbose=True):
    """
    Huấn luyện mạng nơ ron
    
    Args:
        model: Instance của NeuralNetwork
        X_train: Training data
        y_train: Training labels (one-hot encoded)
        X_val: Validation data
        y_val: Validation labels (one-hot encoded)
        epochs: Số epoch huấn luyện
        batch_size: Kích thước batch
        verbose: In thông tin trong quá trình train
    
    Returns:
        history: Dictionary chứa lịch sử train (loss, accuracy)
    """
    history = {
        'train_loss': [],
        'train_acc': [],
        'val_loss': [],
        'val_acc': []
    }
    
    loader = MNISTLoader()
    
    print("=" * 60)
    print("BẮT ĐẦU HUẤN LUYỆN MẠNG NƠ RON")
    print("=" * 60)
    print(f"Số epoch: {epochs}")
    print(f"Batch size: {batch_size}")
    print(f"Learning rate: {model.learning_rate}")
    print(f"Kiến trúc mạng: {model.layer_sizes}")
    print("=" * 60)
    
    # TODO: Implement training loop
    # 1. Với mỗi epoch:
    #    - Chia dữ liệu thành mini-batches
    #    - Train trên từng batch
    #    - Tính loss và accuracy trên tập train
    #    - Tính loss và accuracy trên tập validation
    #    - Lưu lại history
    #    - In kết quả
    
    # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
    
    for epoch in range(epochs):
        epoch_start_time = time.time()
        
        # Tạo mini-batches
        mini_batches = None  # Sử dụng loader.create_mini_batches()
        
        # Train trên từng batch
        epoch_losses = []
        pass  # Lặp qua từng batch và gọi model.train_step()
        
        # Tính average loss cho epoch
        avg_train_loss = None  # Trung bình của epoch_losses
        
        # Tính accuracy trên tập train
        # Hint: Dùng model.predict() và so sánh với y_true
        train_predictions = None  # model.predict(X_train)
        train_true_labels = None  # np.argmax(y_train, axis=1)
        train_acc = None  # Tính accuracy = số dự đoán đúng / tổng số
        
        # Tính loss và accuracy trên tập validation
        val_predictions = None  # model.predict(X_val)
        val_true_labels = None  # np.argmax(y_val, axis=1)
        val_acc = None  # Tính validation accuracy
        
        # Tính validation loss
        val_pred_probs = None  # model.forward(X_val)
        val_loss = None  # model.compute_loss(val_pred_probs, y_val)
        
        # Lưu history
        pass  # Append các giá trị vào history
        
        # In kết quả
        epoch_time = time.time() - epoch_start_time
        if verbose:
            print(f"Epoch {epoch + 1}/{epochs} - {epoch_time:.2f}s - "
                  f"loss: {avg_train_loss:.4f} - acc: {train_acc:.4f} - "
                  f"val_loss: {val_loss:.4f} - val_acc: {val_acc:.4f}")
    
    # ==========================================
    
    print("=" * 60)
    print("HOÀN THÀNH HUẤN LUYỆN")
    print("=" * 60)
    
    return history


def main():
    """
    Hàm chính để chạy quá trình huấn luyện
    """
    # Thiết lập random seed để kết quả có thể tái tạo
    np.random.seed(42)
    
    # TODO: Hoàn thành hàm main
    # 1. Load dữ liệu MNIST
    # 2. Chia tập train thành train và validation (80-20)
    # 3. Tạo model với kiến trúc phù hợp
    # 4. Huấn luyện model
    # 5. Lưu model và history
    
    # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
    
    print("Đang tải dữ liệu MNIST...")
    # Load data
    loader = MNISTLoader()
    X_train_full, y_train_full, X_test, y_test = None  # loader.load_data()
    
    # Chia train thành train và validation (80-20)
    # Hint: Lấy 48000 mẫu đầu cho train, 12000 mẫu sau cho validation
    split_idx = None  # Tính split index
    X_train = None  # Lấy phần train
    y_train = None
    X_val = None  # Lấy phần validation
    y_val = None
    
    print(f"\nKích thước dữ liệu:")
    print(f"Train: {X_train.shape}")
    print(f"Validation: {X_val.shape}")
    print(f"Test: {X_test.shape}")
    
    # Tạo model
    # Hint: Input size = 784, Output size = 10
    # Có thể thử kiến trúc: [784, 128, 64, 10]
    layer_sizes = None  # Định nghĩa kiến trúc
    learning_rate = None  # Thiết lập learning rate (thử 0.01 hoặc 0.1)
    
    print(f"\nTạo mạng nơ ron với kiến trúc: {layer_sizes}")
    model = None  # NeuralNetwork(layer_sizes, learning_rate)
    
    # Huấn luyện
    history = None  # train_model(model, X_train, y_train, X_val, y_val, 
                    #              epochs=20, batch_size=128)
    
    # Lưu model
    print("\nĐang lưu model...")
    pass  # save_model(model, 'model.pkl')
    print("Đã lưu model vào model.pkl")
    
    # Vẽ biểu đồ training history
    print("Đang vẽ biểu đồ training history...")
    pass  # plot_training_history(history, save_path='training_history.png')
    print("Đã lưu biểu đồ vào training_history.png")
    
    # ==========================================
    
    print("\n" + "=" * 60)
    print("HOÀN THÀNH!")
    print("=" * 60)


if __name__ == "__main__":
    main()
