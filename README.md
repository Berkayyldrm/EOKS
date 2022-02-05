# Sıcaklık ve Motor Kontrol Sisteminin Tasarımı ve Uygulaması

Projede sıcaklık ve motor kontrol sistemi ayrı olarak tasarlanmıştır. Motor kontrol sistemi tasarlanmasının amacı, encoderli bir DC motorun hız kontrolünü yapacak sistem tasarımı ve gerçeklemesidir. Encoderli DC motor kontrolünde PID algoritması kullanılmıştır. PID algoritması Arduino IDE üzerinden yazılmıştır. PID algoritmasının değerleri de visual studioda yazılan masaüstü uygulaması üzerinden alınıyor. Sıcaklık kontrol sisteminin tasarlanmasının amacı, ortamda belli bir nesnenin sıcaklığının istenen değerde tutabilmektir. Bu sistemde ısıtmak için röle, soğutmak için de DC motora bağlı fan kullanılmıştır. Proje kodları ekte verilmiştir.

</br > ![Go to Goal Behaviour System](/Motor_Kontrol_Kodları/sema.png)

Bilgisayar ile mikrodenetleyicinin haberleşmesi seri haberleşme ile yapılmıştır. Arduino başka mikroişlemci veya sensorler ile veri alım-iletimini kurabilmek için haberleşme protokolünü kullanır. Seri haberleşmede Arduino’yla başka cihazlar arasında çift taraflı iletişim kurmasını sağlamaktadır. Arduino’nun üzerinde bulunan seri haberleşme ünitesine UART ismi denilmektedir. Kullanmış olunan Arduino’nun modeline göre UART sayısı bir veya daha fazla adet bulunabilir. Arduino üzerinde 1 Adet, Arduino Mega üzerinde ise 3 Adet UART bulunur.
	Haberleşme için bilgi gönderici TX(transmitter) ve alıcı olan pin RX(receiver) olarak adlandırılmaktadır. Uno üzerindeki TX pini 1, RX pini 0 nolu pinlerdir. Bilgisayar ile kartınız arasındaki bağlantıyı tamamladıktan sonra serial port ekranına ulaşabilir ve bu ekranı kullanarak gerçekleştirmiş olduğunuz devrenin Arduinuo kartıyla haberleşme ekranına ulaşabilirsiniz

</br > ![Go to Goal Behaviour System](/Motor_Kontrol_Kodları/eloktronik-tasarim.png)

Motor kontrol sisteminin sonucunda PID kontrolorün motor hızına etkisi gözlemlenmiştir. Kp, Ki, Kd değerleri masaüstü uygulama üzerinden değiştirilerek etkileri görülmüştür.  Oransal denetleyicilerin (Kp), yükselme zamanını azaltmada etkisi vardır ve azaltır, ama asla tamamen yok etmez (kararlı hal hatası). İntegral denetleyicinin (Ki) karalı hal hatasının çıkarılmasında etkisi vardır ancak bu geçici tepkinin daha kötü olmasına sebep olabilir. Türevsel denetleyicinin (Kd) sistemin kararlılığının artmasında etkisi vardır, aşmayı azaltır ve geçici tepkiyi düzeltir.
	Basit sıcaklık kontrol sisteminde sensörün hassasiyetinden dolayı hatalı değerler ölçülüp yanlış sonuçlar verdiği görülmüştür. Kullanılan DHT11 sensör kartı yerine daha iyi bir sıcaklık sensörü kullanılması gerekmektedir

## Created by

## **[kajun1337](https://github.com/kajun1337 "kajun1337") &  [Berkayyldrm](https://github.com/Berkayyldrm "Berkayyldrm")**
![](https://img.shields.io/github/release/pandao/editor.md.svg)
##  Kaynakça

[1]Ceren, Yeter. «PID NEDİR?» 2016.
[2]Küçüködük, B. Tuğçe. Robotistan. 17 09 2018. https://maker.robotistan.com/nrf24l01-dht11-arduino/ (erişildi: Ocak 05, 2022).
[3]MikroCore. Şubat 2015. http://www.mikrocore.com/genel/arduino-seri (erişildi: Ocak 03, 2022).
[4]Robotistan. tarih yok. https://www.robotistan.com/12-v-37-mm-10000-rpm-enkoderli-yuksek-guclu-reduktorsuz-dc-motor (erişildi: Ocak 05, 2022).
[5]Robotistan. tarih yok. https://www.robotistan.com/l298n-voltaj-regulatorlu-cift-motor-surucu-karti (erişildi: Ocak 04, 2022).
[6]Semiz, Tayfur Yağız. Robotistan. Mayıs 2018. https://maker.robotistan.com/arduino-uno/ (erişildi: Ocak 1, 2021).



