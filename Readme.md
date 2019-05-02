Cài đặt và sử dụng đồ họa trên Dev-C++
Bước 1. Download và cài đặt Dev-C++
Bước 2. Download 2 file “graphics.h” và “libbgi.a”
Bước 3. Cấu hình Compiler Options: TDM-GCC 4.9.2 32bit Release
Bước 3. Copy flie “graphics.h” vào folder include (C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include)
        và file “libbgi.a” vào folder lib (C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\lib)
Bước 4. Tạo mới một Project
        File -> New -> Project...
        Tab Basic: 
            Console Graphics Application
            A console application: C++
            Name: ComputerGraphics
            OK
        Save As: Documents -> ComputerGraphics.dev -> Save
Bước 5. Cấu hình cho thẻ project
        Project -> Project Options
        Tab: Parameters
             Ô Linker: paste code sau
                lbgi
                lgdi32
                lcomdlg32
                luuid
                loleaut32
                lole32
              OK
