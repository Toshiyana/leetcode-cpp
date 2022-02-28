#include <bits/stdc++.h>

#include "Television.h"

using namespace std;

int main()
{
    Television tv; // Television クラスの変数 tv を宣言
                   // クラスを「新しい型」として用いている
                   // この時点でコンストラクタが呼ばれる

    tv.printStatus(); // 確認のために状態表示

    cout << endl;

    tv.setPower(1);   // 電源オン
    tv.setChannel(8); // 8チャンネルにセット
    tv.setVolume(10); // ボリュームを10に
    tv.printStatus();

    cout << endl;

    tv.setChannel(4); // 4チャンネルにセット
    tv.printStatus();
}