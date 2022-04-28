// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<fstream>
#include<string>
#include<vector>

#define ENEMY_NUM 100

using namespace std;

int main()
{    
    //書き込むファイルを開く
    const std::string fileName = "EnemyArrivalTime.csv";
    std::ofstream ofs(fileName);

    if (!ofs)
    {
        return -1;
    }

    //情報名の入力
    ofs << "EnemyArrivalTime" << endl;

    for (int i = 0; i < ENEMY_NUM; i++)
    {
        ofs << i * 10 << endl;
    }

    //読み込むファイルを開く
    std::ifstream ifs(fileName);

    //一行読み込むための変数
    std::string line;

    //値格納用変数
    std::vector<int> enemyArrivalTime;

    // 読み込めなかったら異常終了するよ！！！！！！！！！！！！
    if (!ifs)
    {
        return -1;
    }

    while (true)
    {
        //一行取得
        std::getline(ifs, line);

        //取得した文字が同じかどうか
        if (line.compare("EnemyArrivalTime") == 0)
        {            
            //cout << line << endl;
            break;
        }
    }

    //敵の数分回す
    for (int i = 0; i < ENEMY_NUM; i++)
    {
        //敵の出現時間を取得する
        std::getline(ifs, line);

        //文字列をint型に変換して保管
        enemyArrivalTime.push_back(std::stoi(line));
    }

    //敵の出現時間を表示するs
    for (int i = 0; i < ENEMY_NUM; i++)
    {
        cout << enemyArrivalTime[i] << endl;
    }

    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
