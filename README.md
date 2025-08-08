# Vie-type
Gõ tiếng Việt cho Windows

## Tính năng
Mặc định, OpenKey cho phép gõ với chế độ bỏ dấu tự do, không cần phải bỏ dấu sau nguyên âm.
* Hỗ trợ kiểu gõ:
	* Telex
	* VNI
	* Simple Telex
	* Có thể yêu cầu thêm kiểu gõ.
* Hỗ trợ bảng mã:
	* Unicode dựng sẵn
	* TCVN3 (ABC)
	* VNI Windows
	* Unicode Tổ hợp
	* Vietnamese locale CP 1258
* Chính tả:
	* Bật tắt kiểm tra chính tả
	* Tự khôi phục phím với từ sai
	* Cho phép chữ "z w j f" làm phụ âm đầu
	* Tạm tắt chính tả bằng phím Ctrl
	* Tạm tắt OpenKey bằng phím Alt
* Tùy chọn:
	* Tự cấu hình phím tắt chuyển Anh - Việt
	* Bỏ dấu kiểu mới (oà, uý) và kiểu cũ (òa úy)
	* Sửa lỗi gợi ý trên thanh địa chỉ trình duyệt, Excel
	* Hiện bảng điều khiển khi khởi động
	* Hai loại biểu tượng trên system tray (đồng bộ với Win10)
	* Khởi động cùng Windows.
	* Chạy với chế độ Admin.
	* Sửa lỗi trên các trình duyệt Chromium
	* Hỗ trợ các ứng dụng metro trên Windows 10
* Công cụ và tính năng nâng cao:
	* Loại trừ ứng dụng thông minh
	* Tự ghi nhớ bảng mã theo ứng dụng
	* Viết Hoa chữ cái đầu câu
	* Gõ nhanh (cc=ch, gg=gi, kk=kh, nn=ng, qq=qu, pp=ph, tt=th)
	* Gõ tắt và công cụ soạn gõ tắt.
	* Chuyển mã với nhiều tùy chọn.

 * ## Cài đặt
- Vào [đây](https://github.com/tuyenvm/OpenKey/releases/latest) tải file `.zip` phiên bản mới nhất về máy, giải nén vào nơi bất kỳ.
- Nhấp đúp vô `OpenKey.exe` để chạy chương trình.
- Lưu ý, khi chạy chương trình lần đầu, Windows sẽ mở một hộp thoại để hỏi bạn, bấm `yes` để đồng ý OpenKey chạy với quyền `admin`
- Xong rồi một biểu tượng chữ `V` sẽ hiện trên system tray, đúp click vô đó để mở bảng điều khiển, cấu hình những thứ bạn cần.
- Xong.

- ## Mã nguồn
- Mã nguồn cho Windows được build thành công với Microsoft Visual Studio 2017.


	* Gõ tắt phụ âm đầu: f->ph, j->gi, w->qu
	* Gõ tắt phụ âm cuối: g->ng, h->nh, k->ch
