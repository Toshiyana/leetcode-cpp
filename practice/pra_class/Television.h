#pragma once

#include <bits/stdc++.h>

using namespace std;

// ヘッダファイル：クラスの宣言を記述。
// 注意：宣言より下のクラスの実装は、別ファイルに分けた方が良い。

class Television
{
    // データメンバ
    int power;
    int channel;
    int volume;

public:
    // コンストラクタ。オブジェクト生成時に自動で呼ばれる。
    Television(void);
    // デストラクタ。オブジェクト消滅時に自動で呼ばれる。
    ~Television(void);

    // メンバ関数
    // - 状態取得用
    int getPower();
    int getChannel();
    int getVolume();

    // - 状態設定用
    void setPower(int p);
    void setChannel(int c);
    void setVolume(int v);

    // - 状態表示用
    void printStatus();
};

// コンストラクタ。オブジェクト生成時に自動で呼ばれる。
Television::Television()
{
    power = 0;   // 電源オフ
    channel = 1; // チャンネル1。首都圏ではNHK。
    volume = 0;  // ボリューム0。
}

// デストラクタ。オブジェクト消滅時に自動で呼ばれる。
Television::~Television()
{
}

// メンバ関数
// - 値の取得用関数（getter）3つ
int Television::getPower()
{
    return power;
}

int Television::getChannel()
{
    return channel;
}

int Television::getVolume()
{
    return volume;
}

// - 値の設定用関数（setter）3つ
void Television::setPower(int p)
{
    power = p;
}

void Television::setChannel(int c)
{
    channel = c;
}

void Television::setVolume(int v)
{
    volume = v;
}

// - 状態表示用関数
void Television::printStatus()
{
    if (power == 1)
        cout << "電源はONです。\n";
    else
    {
        cout << "電源はOFFです。\n";
        return; // オフの場合は、ここから先へ進まずに終了。
    }

    cout << "チャンネルは" << channel << "です。\n";
    cout << "ボリュームは" << volume << "です。\n";
}