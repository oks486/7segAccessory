/* 
 *  7セグアクセサリに表示データを書き込むスケッチ
 *  Author: oks486
 */

// セグメント個別点灯のマクロ定義 (基本的に変更しない)
#define BLANK   0b00000000  // blank

#define SEG_A   0b01000000
#define SEG_B   0b10000000
#define SEG_C   0b00100000
#define SEG_D   0b00010000
#define SEG_E   0b00001000
#define SEG_F   0b00000100
#define SEG_G   0b00000010
#define SEG_DOT 0b00000001

// 数字点灯のマクロ定義 (基本的に変更しない)
#define NUM_0   0b11111100
#define NUM_1   0b10100000
#define NUM_2   0b11011010
#define NUM_3   0b11110010
#define NUM_4   0b10100110
#define NUM_5   0b01110110
#define NUM_6   0b01111110
#define NUM_7   0b11100000
#define NUM_8   0b11111110
#define NUM_9   0b11110110
#define NUM_A   0b11101110
#define NUM_B   0b00111110
#define NUM_C   0b01011100
#define NUM_D   0b10111010
#define NUM_E   0b01011110
#define NUM_F   0b01001110

// 書き込みモードに入るためのデータ (変更不可)
unsigned char commandData[] = {'+','+','+'};

// 7セグアクセサリに書き込むデータ (ここを編集)
unsigned char dispData[] = {
      50,   // ウェイト数
      // ウェイト数は、あるデータを表示して次のデータを表示するまでの
      // 待ち時間です。値が1増えるごとに約10ミリ秒長くなります。
      // 設定できる値は255までです。

      1,    // モード (変更不可)
      // 必ず 1 に設定してください

      11,   // データの長さ
      // 表示データの長さを設定します。最大の長さは250です。
      // 実際の表示データ数より小さい数字を設定すると、書き込んだデータが
      // 最後まで表示されません。逆に大きいと意図しないデータが表示されます。
      // 表示のされ方としては、最後のデータまで表示すると、初めのデータに戻り、
      // 以降無限にループして表示します。

      // 表示データ
      // マクロ定義を用いて記述します。
      // 次のデータ列は「0 1 2 3 4 5 6 7 8 9 (blank)」と表示されます。
      NUM_0,  // 0
      NUM_1,  // 1
      NUM_2,  // 2
      NUM_3,  // 3
      NUM_4,  // 4
      NUM_5,  // 5
      NUM_6,  // 6
      NUM_7,  // 7
      NUM_8,  // 8
      NUM_9,  // 9
      BLANK,  // (blank)

      // その他の記述例
      // SEG_A | SEG_D | SEG_G,   // セグメントa,d,gが点灯します
      // NUM_0 | SEG_DOT,         // 数字の0とdotが点灯します
      // 配列最後のカンマはあってもなくても良いです
      };

// これ以降変更不可
void setup() {
  Serial.begin(9600);
}

void loop() {
  for (unsigned int i = 0; i < sizeof(commandData); i++) {
    Serial.write(commandData[i]);
    delay(10);
  }
  for (unsigned int i = 0; i < sizeof(dispData); i++) {
    Serial.write(dispData[i]);
    delay(10);
  }
  
  while(1);
}

