Bài 2: LED điều khiển bằng nút nhấn
Yêu cầu

Cấu hình 1 LED ở chế độ Output.

Cấu hình 1 nút nhấn ở chế độ Input.

LED thay đổi trạng thái mỗi lần người dùng nhấn nút.

Mục tiêu

Làm quen với GPIO Input.

Xử lý trạng thái nhấn nút.

Kết hợp Input và Output để điều khiển LED.

Gợi ý thực hiện

LED: cấu hình Output Push-Pull.

Nút nhấn: cấu hình Input Pull-up/Pull-down (tùy mạch).

Trong vòng lặp:

Đọc trạng thái nút nhấn.

Nếu phát hiện nút nhấn (chuyển từ chưa nhấn → nhấn), đổi trạng thái LED.

Có thể cần chống dội phím (debounce) bằng delay nhỏ (~20 ms).
