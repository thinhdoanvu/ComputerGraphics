```
import numpy as np
import matplotlib.pyplot as plt

# Tạo ảnh 5x5 pixel, toàn bộ là màu đen (giá trị 0)
image = np.zeros((225, 225), dtype=np.uint8)

# Đặt pixel ở giữa thành màu trắng (giá trị 255)
image[105, 105] = 255

# Hiển thị ảnh
plt.imshow(image, cmap="gray", vmin=0, vmax=255)
plt.axis("off")  # Tắt trục
plt.show()
```
![image](https://github.com/user-attachments/assets/95e359c7-3141-4d99-8408-dc05c8943029)
