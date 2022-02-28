#include <bits/stdc++.h>

#include "Television.h"

using namespace std;

int main()
{

    //----------------------------------------------------------------
    // ポインタでオブジェクトを定義した場合、
    // メンバ関数の呼び出しにアロー演算子（->）を利用
    //----------------------------------------------------------------

    // テレビクラスのポインタの宣言
    // （ポインタtvp自体は、スタック領域に保存）
    Television *tvp;

    // テレビクラスのオブジェクトをヒープ領域に確保(new演算子の利用)
    // これにより、ポインタの指す先が決まる。 （ポインタtvpはヒープ領域に作られたオブジェクトを指すようになる。）
    tvp = new Television();

    tvp->printStatus();

    cout << endl;

    tvp->setPower(1);
    tvp->setChannel(8);
    tvp->setVolume(10);
    tvp->printStatus();

    cout << endl;

    tvp->setChannel(4);
    tvp->printStatus();

    delete tvp; // newで確保したオブジェクトをdeleteで解放

    // //----------------------------------------------------------------
    // // 通常の変数でオブジェクトを定義した場合、
    // // メンバ関数の呼び出しにドット演算子（.）を利用
    // //----------------------------------------------------------------

    // Television tv; // Television クラスの変数 tv を宣言
    //                // クラスを「新しい型」として用いている
    //                // この時点でコンストラクタが呼ばれる

    // tv.printStatus(); // 確認のために状態表示

    // cout << endl;

    // tv.setPower(1);   // 電源オン
    // tv.setChannel(8); // 8チャンネルにセット
    // tv.setVolume(10); // ボリュームを10に
    // tv.printStatus();

    // cout << endl;

    // tv.setChannel(4); // 4チャンネルにセット
    // tv.printStatus();
}