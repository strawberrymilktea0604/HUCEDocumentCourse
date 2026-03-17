"""
Bài thực hành: Mạng Nơ Ron Nhân Tạo (Neural Network)
File: evaluation.py
Mô tả: Đánh giá hiệu suất model với các metrics chi tiết
"""

import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
from neural_network import NeuralNetwork
from data_loader import MNISTLoader
from utils import load_model


def calculate_accuracy(y_true, y_pred):
    """
    Tính Accuracy
    
    Args:
        y_true: Nhãn thực tế (n,)
        y_pred: Nhãn dự đoán (n,)
    
    Returns:
        accuracy: Độ chính xác
    """
    # TODO: Tính accuracy
    # Công thức: Accuracy = (Số dự đoán đúng) / (Tổng số mẫu)
    
    # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
    pass  # Thay thế dòng này
    # ==========================================


def calculate_precision_recall_f1(y_true, y_pred, num_classes=10):
    """
    Tính Precision, Recall, F1-Score cho từng class
    
    Args:
        y_true: Nhãn thực tế (n,)
        y_pred: Nhãn dự đoán (n,)
        num_classes: Số lượng class
    
    Returns:
        precision: Array precision cho từng class (num_classes,)
        recall: Array recall cho từng class (num_classes,)
        f1: Array F1-score cho từng class (num_classes,)
    """
    # TODO: Tính Precision, Recall, F1 cho từng class
    # Với mỗi class:
    #   - True Positive (TP): Dự đoán đúng là class đó
    #   - False Positive (FP): Dự đoán là class đó nhưng sai
    #   - False Negative (FN): Thực tế là class đó nhưng dự đoán sai
    #   - Precision = TP / (TP + FP)
    #   - Recall = TP / (TP + FN)
    #   - F1 = 2 * (Precision * Recall) / (Precision + Recall)
    
    # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
    precision = np.zeros(num_classes)
    recall = np.zeros(num_classes)
    f1 = np.zeros(num_classes)
    
    for class_id in range(num_classes):
        # Tính True Positive
        tp = None  # Số mẫu được dự đoán đúng là class_id
        
        # Tính False Positive
        fp = None  # Số mẫu được dự đoán là class_id nhưng sai
        
        # Tính False Negative
        fn = None  # Số mẫu thực tế là class_id nhưng dự đoán sai
        
        # Tính Precision
        if tp + fp > 0:
            pass  # precision[class_id] = ...
        else:
            precision[class_id] = 0.0
        
        # Tính Recall
        if tp + fn > 0:
            pass  # recall[class_id] = ...
        else:
            recall[class_id] = 0.0
        
        # Tính F1
        if precision[class_id] + recall[class_id] > 0:
            pass  # f1[class_id] = ...
        else:
            f1[class_id] = 0.0
    
    return precision, recall, f1
    # ==========================================


def calculate_confusion_matrix(y_true, y_pred, num_classes=10):
    """
    Tính Confusion Matrix
    
    Args:
        y_true: Nhãn thực tế (n,)
        y_pred: Nhãn dự đoán (n,)
        num_classes: Số lượng class
    
    Returns:
        confusion_matrix: Ma trận confusion (num_classes, num_classes)
                          cm[i][j] = số mẫu có nhãn thực i được dự đoán là j
    """
    # TODO: Tính confusion matrix
    # confusion_matrix[i][j] = số lượng mẫu có nhãn thực tế là i nhưng được dự đoán là j
    # Hint: Lặp qua từng mẫu hoặc dùng numpy indexing
    
    # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
    cm = np.zeros((num_classes, num_classes), dtype=int)
    
    # Cách 1: Dùng vòng lặp
    pass  # Lặp qua từng mẫu và tăng cm[y_true[i]][y_pred[i]]
    
    # Cách 2: Dùng numpy (nâng cao)
    # Hint: np.add.at() hoặc indexing thông minh
    
    return cm
    # ==========================================


def plot_confusion_matrix(cm, save_path='confusion_matrix.png'):
    """
    Vẽ confusion matrix dưới dạng heatmap
    
    Args:
        cm: Confusion matrix
        save_path: Đường dẫn lưu hình
    """
    plt.figure(figsize=(10, 8))
    sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', 
                xticklabels=range(10), yticklabels=range(10))
    plt.xlabel('Predicted Label', fontsize=12)
    plt.ylabel('True Label', fontsize=12)
    plt.title('Confusion Matrix', fontsize=14)
    plt.tight_layout()
    plt.savefig(save_path, dpi=150, bbox_inches='tight')
    print(f"Đã lưu confusion matrix vào {save_path}")
    plt.show()


def plot_metrics_per_class(precision, recall, f1, save_path='metrics_per_class.png'):
    """
    Vẽ biểu đồ các metrics theo từng class
    
    Args:
        precision: Array precision
        recall: Array recall
        f1: Array F1-score
        save_path: Đường dẫn lưu hình
    """
    x = np.arange(len(precision))
    width = 0.25
    
    fig, ax = plt.subplots(figsize=(12, 6))
    ax.bar(x - width, precision, width, label='Precision', alpha=0.8)
    ax.bar(x, recall, width, label='Recall', alpha=0.8)
    ax.bar(x + width, f1, width, label='F1-Score', alpha=0.8)
    
    ax.set_xlabel('Class', fontsize=12)
    ax.set_ylabel('Score', fontsize=12)
    ax.set_title('Precision, Recall, F1-Score per Class', fontsize=14)
    ax.set_xticks(x)
    ax.set_xticklabels(range(10))
    ax.legend()
    ax.grid(axis='y', alpha=0.3)
    
    plt.tight_layout()
    plt.savefig(save_path, dpi=150, bbox_inches='tight')
    print(f"Đã lưu biểu đồ metrics vào {save_path}")
    plt.show()


def evaluate_model(model, X_test, y_test):
    """
    Đánh giá toàn diện model
    
    Args:
        model: Model đã train
        X_test: Test data
        y_test: Test labels (one-hot hoặc integer)
    
    Returns:
        results: Dictionary chứa các metrics
    """
    print("=" * 60)
    print("ĐÁNH GIÁ MODEL TRÊN TẬP TEST")
    print("=" * 60)
    
    # TODO: Hoàn thành đánh giá model
    # 1. Dự đoán trên test set
    # 2. Tính các metrics: accuracy, precision, recall, F1
    # 3. Tính confusion matrix
    # 4. Hiển thị kết quả
    
    # ===== SINH VIÊN HOÀN THÀNH PHẦN NÀY =====
    
    # Chuyển y_test về dạng integer nếu đang là one-hot
    if y_test.ndim == 2:
        y_test_labels = None  # np.argmax(y_test, axis=1)
    else:
        y_test_labels = y_test
    
    # Dự đoán
    print("\nĐang thực hiện dự đoán...")
    y_pred = None  # model.predict(X_test)
    
    # Tính accuracy
    print("\nĐang tính các metrics...")
    accuracy = None  # calculate_accuracy(y_test_labels, y_pred)
    
    # Tính precision, recall, F1
    precision, recall, f1 = None, None, None  # calculate_precision_recall_f1(y_test_labels, y_pred)
    
    # Tính confusion matrix
    cm = None  # calculate_confusion_matrix(y_test_labels, y_pred)
    
    # ==========================================
    
    # In kết quả
    print("\n" + "=" * 60)
    print("KẾT QUẢ ĐÁNH GIÁ")
    print("=" * 60)
    print(f"\nOverall Accuracy: {accuracy:.4f} ({accuracy*100:.2f}%)")
    
    print("\n" + "-" * 60)
    print("Metrics per class:")
    print("-" * 60)
    print(f"{'Class':<10} {'Precision':<12} {'Recall':<12} {'F1-Score':<12}")
    print("-" * 60)
    
    for i in range(10):
        print(f"{i:<10} {precision[i]:<12.4f} {recall[i]:<12.4f} {f1[i]:<12.4f}")
    
    print("-" * 60)
    print(f"{'Average':<10} {np.mean(precision):<12.4f} {np.mean(recall):<12.4f} {np.mean(f1):<12.4f}")
    print("-" * 60)
    
    # Vẽ biểu đồ
    print("\nĐang vẽ biểu đồ...")
    plot_confusion_matrix(cm)
    plot_metrics_per_class(precision, recall, f1)
    
    # Lưu kết quả
    results = {
        'accuracy': accuracy,
        'precision': precision,
        'recall': recall,
        'f1': f1,
        'confusion_matrix': cm
    }
    
    print("\n" + "=" * 60)
    print("HOÀN THÀNH ĐÁNH GIÁ!")
    print("=" * 60)
    
    return results


def analyze_errors(model, X_test, y_test, num_errors=10):
    """
    Phân tích các mẫu dự đoán sai
    
    Args:
        model: Model đã train
        X_test: Test data
        y_test: Test labels
        num_errors: Số lượng mẫu lỗi hiển thị
    """
    print("\n" + "=" * 60)
    print("PHÂN TÍCH CÁC DỰ ĐOÁN SAI")
    print("=" * 60)
    
    # Chuyển y_test về dạng integer
    if y_test.ndim == 2:
        y_test_labels = np.argmax(y_test, axis=1)
    else:
        y_test_labels = y_test
    
    # Dự đoán
    y_pred = model.predict(X_test)
    probs = model.forward(X_test)
    
    # Tìm các mẫu dự đoán sai
    error_indices = np.where(y_pred != y_test_labels)[0]
    print(f"\nTổng số lỗi: {len(error_indices)}/{len(y_test)} "
          f"({len(error_indices)/len(y_test)*100:.2f}%)")
    
    if len(error_indices) == 0:
        print("Không có lỗi nào!")
        return
    
    # Lấy random một số lỗi
    num_errors = min(num_errors, len(error_indices))
    selected_errors = np.random.choice(error_indices, num_errors, replace=False)
    
    # Hiển thị
    fig, axes = plt.subplots(2, 5, figsize=(15, 6))
    axes = axes.ravel()
    
    for i, idx in enumerate(selected_errors):
        image = X_test[idx].reshape(28, 28)
        true_label = y_test_labels[idx]
        pred_label = y_pred[idx]
        confidence = np.max(probs[idx])
        
        axes[i].imshow(image, cmap='gray')
        axes[i].axis('off')
        axes[i].set_title(f'True: {true_label}\nPred: {pred_label} ({confidence:.2f})',
                          color='red', fontsize=10)
    
    plt.tight_layout()
    plt.savefig('error_analysis.png', dpi=150, bbox_inches='tight')
    print("Đã lưu phân tích lỗi vào error_analysis.png")
    plt.show()


def main():
    """
    Hàm chính để chạy evaluation
    """
    print("=" * 60)
    print("EVALUATION - ĐÁNH GIÁ MODEL")
    print("=" * 60)
    
    # Load model
    print("\nĐang load model...")
    model = load_model('model.pkl')
    print("Đã load model thành công!")
    
    # Load test data
    print("\nĐang load dữ liệu test...")
    loader = MNISTLoader()
    X_train, y_train, X_test, y_test = loader.load_data()
    
    # Đánh giá model
    results = evaluate_model(model, X_test, y_test)
    
    # Phân tích lỗi
    analyze_errors(model, X_test, y_test, num_errors=10)
    
    print("\nHoàn thành đánh giá!")


if __name__ == "__main__":
    main()
