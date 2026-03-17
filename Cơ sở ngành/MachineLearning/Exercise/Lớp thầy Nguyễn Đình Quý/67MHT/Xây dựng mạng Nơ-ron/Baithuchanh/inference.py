"""
Bài thực hành: Mạng Nơ Ron Nhân Tạo (Neural Network)
File: inference.py
Mô tả: Sử dụng model đã train để dự đoán trên dữ liệu mới
"""

import numpy as np
import matplotlib.pyplot as plt
from neural_network import NeuralNetwork
from data_loader import MNISTLoader
from utils import load_model


def predict_single_image(model, image, true_label=None):
    """
    Dự đoán nhãn cho một ảnh đơn
    
    Args:
        model: Model đã train
        image: Ảnh đầu vào (784,) hoặc (28, 28)
        true_label: Nhãn thực tế (optional)
    
    Returns:
        predicted_class: Class được dự đoán
        confidence: Độ tin cậy của dự đoán
    """
    # TODO: Implement dự đoán cho một ảnh
    # 1. Reshape ảnh về dạng (1, 784) nếu cần
    # 2. Dùng model.forward() để lấy probability
    # 3. Lấy class có xác suất cao nhất
    
    # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
    
    # Chuẩn bị input
    if image.shape == (28, 28):
        pass  # Flatten ảnh
    
    if image.ndim == 1:
        pass  # Reshape thành (1, 784)
    
    # Forward pass
    probs = None  # model.forward(image)
    
    # Lấy predicted class và confidence
    predicted_class = None  # np.argmax(probs)
    confidence = None  # probs[0, predicted_class]
    
    # In kết quả
    print(f"Predicted class: {predicted_class}")
    print(f"Confidence: {confidence:.4f}")
    if true_label is not None:
        print(f"True label: {true_label}")
        print(f"Correct: {predicted_class == true_label}")
    
    return predicted_class, confidence
    # ==========================================


def predict_batch(model, images, true_labels=None):
    """
    Dự đoán nhãn cho một batch ảnh
    
    Args:
        model: Model đã train
        images: Batch ảnh (n, 784)
        true_labels: Nhãn thực tế (n,) - optional
    
    Returns:
        predictions: Array các class được dự đoán (n,)
        confidences: Array độ tin cậy (n,)
    """
    # TODO: Implement dự đoán cho batch
    # 1. Forward pass qua model
    # 2. Lấy predicted classes
    # 3. Lấy confidence cho từng prediction
    
    # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
    
    # Forward pass
    probs = None  # model.forward(images)
    
    # Predictions
    predictions = None  # np.argmax(probs, axis=1)
    
    # Confidence (max probability)
    confidences = None  # np.max(probs, axis=1)
    
    # Tính accuracy nếu có true labels
    if true_labels is not None:
        accuracy = None  # Tính accuracy
        print(f"Batch accuracy: {accuracy:.4f}")
    
    return predictions, confidences
    # ==========================================


def visualize_predictions(model, images, true_labels, num_samples=10):
    """
    Hiển thị ảnh cùng với dự đoán và nhãn thực tế
    
    Args:
        model: Model đã train
        images: Ảnh đầu vào (n, 784)
        true_labels: Nhãn thực tế (n,)
        num_samples: Số lượng ảnh hiển thị
    """
    # Lấy random samples
    indices = np.random.choice(len(images), num_samples, replace=False)
    
    # Dự đoán
    predictions, confidences = predict_batch(model, images[indices], true_labels[indices])
    
    # Vẽ ảnh
    fig, axes = plt.subplots(2, 5, figsize=(15, 6))
    axes = axes.ravel()
    
    for i, idx in enumerate(indices):
        # Reshape ảnh về 28x28
        image = images[idx].reshape(28, 28)
        
        # Vẽ ảnh
        axes[i].imshow(image, cmap='gray')
        axes[i].axis('off')
        
        # Tiêu đề: dự đoán và nhãn thực
        pred = predictions[i]
        conf = confidences[i]
        true = true_labels[idx]
        
        color = 'green' if pred == true else 'red'
        axes[i].set_title(f'Pred: {pred} ({conf:.2f})\nTrue: {true}', 
                          color=color, fontsize=10)
    
    plt.tight_layout()
    plt.savefig('predictions_visualization.png', dpi=150, bbox_inches='tight')
    print("Đã lưu visualization vào predictions_visualization.png")
    plt.show()


def interactive_prediction(model, X_test, y_test):
    """
    Chế độ dự đoán tương tác - người dùng chọn index để dự đoán
    
    Args:
        model: Model đã train
        X_test: Test images
        y_test: Test labels
    """
    print("\n" + "=" * 60)
    print("CHẾ ĐỘ DỰ ĐOÁN TƯƠNG TÁC")
    print("=" * 60)
    print("Nhập index của ảnh để dự đoán (0-9999)")
    print("Nhập 'q' để thoát")
    print("=" * 60)
    
    while True:
        user_input = input("\nNhập index: ").strip()
        
        if user_input.lower() == 'q':
            print("Thoát chế độ dự đoán tương tác")
            break
        
        try:
            idx = int(user_input)
            if idx < 0 or idx >= len(X_test):
                print(f"Index phải trong khoảng [0, {len(X_test)-1}]")
                continue
            
            image = X_test[idx]
            true_label = y_test[idx]
            
            print(f"\nDự đoán cho ảnh index {idx}:")
            pred, conf = predict_single_image(model, image, true_label)
            
            # Hiển thị ảnh
            plt.figure(figsize=(4, 4))
            plt.imshow(image.reshape(28, 28), cmap='gray')
            plt.axis('off')
            color = 'green' if pred == true_label else 'red'
            plt.title(f'Predicted: {pred} (Confidence: {conf:.4f})\nTrue: {true_label}',
                     color=color, fontsize=12)
            plt.show()
            
        except ValueError:
            print("Vui lòng nhập số nguyên hợp lệ hoặc 'q' để thoát")


def main():
    """
    Hàm chính để chạy inference
    """
    print("=" * 60)
    print("INFERENCE - DỰ ĐOÁN VỚI MODEL ĐÃ TRAIN")
    print("=" * 60)
    
    # TODO: Hoàn thành hàm main
    # 1. Load model đã train
    # 2. Load test data
    # 3. Thực hiện dự đoán trên test set
    # 4. Hiển thị kết quả
    
    # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
    
    # Load model
    print("\nĐang load model...")
    model = None  # load_model('model.pkl')
    print("Đã load model thành công!")
    print(f"Kiến trúc: {model.layer_sizes}")
    
    # Load test data
    print("\nĐang load dữ liệu test...")
    loader = MNISTLoader()
    X_train, y_train, X_test, y_test = None  # loader.load_data()
    y_test_labels = None  # np.argmax(y_test, axis=1)
    
    # Dự đoán trên toàn bộ test set
    print("\nĐang dự đoán trên test set...")
    predictions, confidences = None  # predict_batch(model, X_test, y_test_labels)
    
    # Tính accuracy
    accuracy = None  # Tính accuracy trên test set
    print(f"\nTest Accuracy: {accuracy:.4f} ({accuracy*100:.2f}%)")
    
    # Hiển thị một số dự đoán
    print("\nHiển thị một số dự đoán ngẫu nhiên...")
    pass  # visualize_predictions(model, X_test, y_test_labels, num_samples=10)
    
    # Chế độ tương tác (optional)
    use_interactive = input("\nBạn có muốn thử chế độ dự đoán tương tác? (y/n): ").strip().lower()
    if use_interactive == 'y':
        pass  # interactive_prediction(model, X_test, y_test_labels)
    
    # ==========================================
    
    print("\n" + "=" * 60)
    print("HOÀN THÀNH INFERENCE!")
    print("=" * 60)


if __name__ == "__main__":
    main()
