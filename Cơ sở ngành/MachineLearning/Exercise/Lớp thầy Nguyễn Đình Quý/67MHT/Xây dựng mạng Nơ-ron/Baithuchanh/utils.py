"""
Bài thực hành: Mạng Nơ Ron Nhân Tạo (Neural Network)
File: utils.py
Mô tả: Các hàm tiện ích (save/load model, visualization, etc.)
"""

import numpy as np
import pickle
import matplotlib.pyplot as plt


def save_model(model, filepath):
    """
    Lưu model vào file
    
    Args:
        model: Instance của NeuralNetwork
        filepath: Đường dẫn file để lưu
    """
    params = model.get_params()
    
    with open(filepath, 'wb') as f:
        pickle.dump(params, f)
    
    print(f"Đã lưu model vào {filepath}")


def load_model(filepath):
    """
    Load model từ file
    
    Args:
        filepath: Đường dẫn file model
    
    Returns:
        model: Instance của NeuralNetwork đã load
    """
    from neural_network import NeuralNetwork
    
    with open(filepath, 'rb') as f:
        params = pickle.load(f)
    
    # Tạo model mới với cùng kiến trúc
    model = NeuralNetwork(params['layer_sizes'], params['learning_rate'])
    
    # Load parameters
    model.set_params(params)
    
    print(f"Đã load model từ {filepath}")
    return model


def plot_training_history(history, save_path='training_history.png'):
    """
    Vẽ biểu đồ quá trình training
    
    Args:
        history: Dictionary chứa train_loss, train_acc, val_loss, val_acc
        save_path: Đường dẫn lưu hình
    """
    epochs = range(1, len(history['train_loss']) + 1)
    
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 5))
    
    # Plot loss
    ax1.plot(epochs, history['train_loss'], 'b-', label='Training Loss', linewidth=2)
    ax1.plot(epochs, history['val_loss'], 'r-', label='Validation Loss', linewidth=2)
    ax1.set_xlabel('Epoch', fontsize=12)
    ax1.set_ylabel('Loss', fontsize=12)
    ax1.set_title('Training and Validation Loss', fontsize=14)
    ax1.legend()
    ax1.grid(True, alpha=0.3)
    
    # Plot accuracy
    ax2.plot(epochs, history['train_acc'], 'b-', label='Training Accuracy', linewidth=2)
    ax2.plot(epochs, history['val_acc'], 'r-', label='Validation Accuracy', linewidth=2)
    ax2.set_xlabel('Epoch', fontsize=12)
    ax2.set_ylabel('Accuracy', fontsize=12)
    ax2.set_title('Training and Validation Accuracy', fontsize=14)
    ax2.legend()
    ax2.grid(True, alpha=0.3)
    
    plt.tight_layout()
    plt.savefig(save_path, dpi=150, bbox_inches='tight')
    print(f"Đã lưu biểu đồ training history vào {save_path}")
    plt.close()


def visualize_weights(model, layer_idx=0, save_path='weights_visualization.png'):
    """
    Visualize weights của một layer (đặc biệt hữu ích cho layer đầu tiên)
    
    Args:
        model: Instance của NeuralNetwork
        layer_idx: Index của layer muốn visualize
        save_path: Đường dẫn lưu hình
    """
    weights = model.weights[layer_idx]
    
    # Nếu là layer đầu tiên (784 inputs), có thể reshape về 28x28
    if weights.shape[0] == 784:
        num_neurons = min(64, weights.shape[1])  # Hiển thị tối đa 64 neurons
        
        fig, axes = plt.subplots(8, 8, figsize=(12, 12))
        axes = axes.ravel()
        
        for i in range(num_neurons):
            weight_image = weights[:, i].reshape(28, 28)
            axes[i].imshow(weight_image, cmap='gray')
            axes[i].axis('off')
            axes[i].set_title(f'N{i}', fontsize=8)
        
        plt.tight_layout()
        plt.savefig(save_path, dpi=150, bbox_inches='tight')
        print(f"Đã lưu visualization weights vào {save_path}")
        plt.close()
    else:
        print(f"Layer {layer_idx} không phù hợp để visualize (shape: {weights.shape})")


def print_model_summary(model):
    """
    In thông tin tóm tắt về model
    
    Args:
        model: Instance của NeuralNetwork
    """
    print("\n" + "=" * 60)
    print("MODEL SUMMARY")
    print("=" * 60)
    print(f"Architecture: {model.layer_sizes}")
    print(f"Learning Rate: {model.learning_rate}")
    print(f"Number of Layers: {model.num_layers}")
    print("\nLayer Details:")
    print("-" * 60)
    
    total_params = 0
    for i in range(model.num_layers - 1):
        w_shape = model.weights[i].shape
        b_shape = model.biases[i].shape
        layer_params = np.prod(w_shape) + np.prod(b_shape)
        total_params += layer_params
        
        print(f"Layer {i+1}: {model.layer_sizes[i]} -> {model.layer_sizes[i+1]}")
        print(f"  Weights: {w_shape} = {np.prod(w_shape):,} params")
        print(f"  Biases: {b_shape} = {np.prod(b_shape):,} params")
        print(f"  Total: {layer_params:,} params")
        print()
    
    print("-" * 60)
    print(f"Total Parameters: {total_params:,}")
    print("=" * 60)


def plot_sample_predictions(images, true_labels, pred_labels, num_samples=10, 
                           save_path='sample_predictions.png'):
    """
    Hiển thị một số mẫu với dự đoán và nhãn thực tế
    
    Args:
        images: Ảnh (n, 784) hoặc (n, 28, 28)
        true_labels: Nhãn thực tế (n,)
        pred_labels: Nhãn dự đoán (n,)
        num_samples: Số lượng mẫu hiển thị
        save_path: Đường dẫn lưu hình
    """
    indices = np.random.choice(len(images), min(num_samples, len(images)), replace=False)
    
    cols = 5
    rows = (num_samples + cols - 1) // cols
    
    fig, axes = plt.subplots(rows, cols, figsize=(15, 3*rows))
    axes = axes.ravel() if num_samples > 1 else [axes]
    
    for i, idx in enumerate(indices):
        if images[idx].shape == (784,):
            image = images[idx].reshape(28, 28)
        else:
            image = images[idx]
        
        axes[i].imshow(image, cmap='gray')
        axes[i].axis('off')
        
        color = 'green' if true_labels[idx] == pred_labels[idx] else 'red'
        axes[i].set_title(f'True: {true_labels[idx]}\nPred: {pred_labels[idx]}',
                         color=color, fontsize=10)
    
    # Hide unused subplots
    for i in range(len(indices), len(axes)):
        axes[i].axis('off')
    
    plt.tight_layout()
    plt.savefig(save_path, dpi=150, bbox_inches='tight')
    print(f"Đã lưu sample predictions vào {save_path}")
    plt.close()


def calculate_gradients_norm(model):
    """
    Tính norm của gradients (hữu ích để debug vanishing/exploding gradients)
    
    Args:
        model: Instance của NeuralNetwork
    
    Returns:
        weights_norms: List các norm của weights
        biases_norms: List các norm của biases
    """
    weights_norms = []
    biases_norms = []
    
    for i in range(len(model.weights)):
        w_norm = np.linalg.norm(model.weights[i])
        b_norm = np.linalg.norm(model.biases[i])
        
        weights_norms.append(w_norm)
        biases_norms.append(b_norm)
    
    return weights_norms, biases_norms


def create_learning_rate_schedule(initial_lr, decay_rate=0.95, decay_steps=5):
    """
    Tạo learning rate schedule (giảm dần learning rate theo epochs)
    
    Args:
        initial_lr: Learning rate ban đầu
        decay_rate: Tỷ lệ giảm
        decay_steps: Số epoch để giảm learning rate
    
    Returns:
        Function để tính learning rate theo epoch
    """
    def lr_schedule(epoch):
        return initial_lr * (decay_rate ** (epoch // decay_steps))
    
    return lr_schedule


def shuffle_data(X, y, seed=None):
    """
    Shuffle dữ liệu
    
    Args:
        X: Input data
        y: Labels
        seed: Random seed
    
    Returns:
        X_shuffled, y_shuffled
    """
    if seed is not None:
        np.random.seed(seed)
    
    indices = np.random.permutation(len(X))
    return X[indices], y[indices]


def normalize_data(X, mean=None, std=None):
    """
    Normalize dữ liệu (standardization)
    
    Args:
        X: Input data
        mean: Mean để normalize (nếu None, tính từ X)
        std: Standard deviation (nếu None, tính từ X)
    
    Returns:
        X_normalized, mean, std
    """
    if mean is None:
        mean = np.mean(X, axis=0)
    if std is None:
        std = np.std(X, axis=0)
        std[std == 0] = 1  # Tránh chia cho 0
    
    X_normalized = (X - mean) / std
    
    return X_normalized, mean, std


# Test code
if __name__ == "__main__":
    print("Utils module - Testing functions...")
    
    # Test save/load
    from neural_network import NeuralNetwork
    
    print("\n1. Test save/load model:")
    model = NeuralNetwork([784, 128, 10], learning_rate=0.01)
    save_model(model, 'test_model.pkl')
    loaded_model = load_model('test_model.pkl')
    print(f"Original model architecture: {model.layer_sizes}")
    print(f"Loaded model architecture: {loaded_model.layer_sizes}")
    
    print("\n2. Test model summary:")
    print_model_summary(model)
    
    print("\n3. Test learning rate schedule:")
    lr_schedule = create_learning_rate_schedule(0.1, decay_rate=0.9, decay_steps=5)
    for epoch in range(20):
        print(f"Epoch {epoch}: lr = {lr_schedule(epoch):.6f}")
    
    print("\nUtils module tested successfully!")
