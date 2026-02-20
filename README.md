# Tensor Quantization Project (C)

Bu proje, C dilinde basit bir tensor veri yapısı oluşturmayı ve float değerleri int8 formatına quantize etmeyi amaçlayan konsol tabanlı bir uygulamadır.

##  Proje Amacı

* Dinamik bellek yönetimi kullanarak tensor yapısı oluşturmak
* Farklı veri tiplerini desteklemek (float32, float16, int8)
* Float tensor değerlerini int8 formatına quantize etmek

##  Dosya Yapısı

* `main.c` → Programın çalıştırıldığı ana dosya
* `tensor.c` → Tensor fonksiyonlarının implementasyonu
* `tensor.h` → Tensor veri yapısı ve fonksiyon prototipleri

##  Kullanılan Teknolojiler

* C Programlama Dili
* Dinamik Bellek Yönetimi (malloc/free)
* Struct ve Union kullanımı

##  Özellikler

* Tensor oluşturma ve silme
* Tensor içini doldurma
* Float → Int8 quantization
* Basit ve modüler yapı

##  Nasıl Çalıştırılır

Dev-C++ veya GCC ile derlenebilir:

```bash
gcc main.c tensor.c -o tensor_app
./tensor_app
```

##  Örnek Çıktı

```
Quantized Tensor:
127 127 127 127
```

##  Kazanımlar

Bu proje ile:

* Header ve source dosya ayrımı
* Bellek yönetimi
* Temel quantization mantığı
  öğrenilmiştir.

---

Hazırlayan: Umut Korkmaz
