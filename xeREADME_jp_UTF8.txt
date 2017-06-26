||*CID:||+v@@@R~:  2017/06/24                update#=  795;
######################################################################
[Japanese]    v1.29A                                                  ||~v@@@R~

メインフレーム(SPFファイルの編集にも便利) と PC と 両方仕事している人に使い易いエディター。
ホストのSPFをベースにPCのEDITORの便利なキー操作をハイブリッド。

    .Windows版、Linux版あり
    .改行コードなしの固定長レコード/可変長ファイルサポート。
    .UTF8ファイル、EBCDIC(ICUの導入が必要)ファイル編集。              ||~v@@@R~
    .バイナリーエディター(縦2段HEXか横HEX表示）
    .ファイラー(フォルダー表示、削除、改名、複写、実行...)
    .リモートアクセス。
       ftp,samba,rsh,ssh,fuse
    .オプションで変更行に修正タグを自動付与。

  ライセンス:GNU GPL に従う。

                                   By 水巻マチ (sakachin2@yahoo.co.jp)

                                   http://hp.vector.co.jp/authors/VA010562
                                   http://www.geocities.jp/sakachin2/index.htm
                                   GitHub: sakachin2/XE               ||~v@@@I~

WIN版はGUI版とWIN32コンソールアプリケーション版があります。
   Console版:xe.exe はコマンドプロンプトで動きマウスはサポートしていません。
   GUI版:wxe.exe はWTL/ATL版(MFC不使用)でvs2010Expressでコンパイルしたものです
   w64binGit.zipを解凍
Linux版はGUI版:gxe とTerminalEmulator版:xe があります。
   gxe-x.xx.tar.gz を 解凍し ./configure && make でインストール
以下のコンソール版ツールも含まれています
   xads         (Win版のみ)NTFSファイルシステムのADS(Alternative Data Stream)アクセス。
   xbc          簡易計算ツール。
   xci          C/C++/Javaテキストファイルのインデンテーション
   xcv          コード変換ツール。(SJIS,EUC,Unicode,UTF-8,EBCDIC,任意のコードページ)
   xcvsjisc     ソースファイル中のSJISコードを８進表記に変換する。
   xdc          ディレクトリー比較ツール
   xdd          ディレクトリー削除ツール
   xdig         ディレクトリーウォークツール
                ディレクトリー内の全サブディレクトリー/ファイルに指定の
                コマンドを作用させるプログラム.
   xds          ディレクトリーサイズ表示ツール
   xfc          ファイル比較ツール
   xff          サイズ、タイムスタンプによるファイルサーチ
   xfg          テキスト/バイナリ－(Recursive)ファイル文字列探索
   xfmt         ファイルフィールドフォーマッター
   xfs          ファイルの分割/統合.大きなファイルのディスケットへの
                バックアップ/リストアーに使えます
   xkp          (WIN)プロセスIDの表示とプロセスのkill
   xlow         大文字ファイル名を小文字に改名。
   xmj          2 ファイルマッチング。
   xpe          errno(libcのエラー番号)の説明を表示する。
   xts          ファイルのタイムスタンプの表示/変更
   xver         OSバージョンからERRORLEVELを設定

   xprint       テキストファイルプリントユーティリティ
   gxp          Linux GTKPrint版 xprint


その他のフォルダーの内容
  xehelp:
    Browser用ヘルプファイル
    ワークディレクトリーに置くか、xehelp環境変数                      ||~v@@@I~
    あるいは/hdコマンドラインパラメータで位置指定する。               ||~v@@@I~
    Linux版でのこれ以外の置き場所はxelnxj.txtを参照してください       ||~v@@@I~
  sample\doc:                                                         ||~v@@@R~
    テキストファイル形式のマニュアル
      xej.txt/xee.txt
      xereadmj.txt/xereadme.txt
      xelnxj.txt/xelnxe.txt(Linux版用)
      xewxej.txt/xewxee.txt(GUI版:wxe/gxe用)
  sample\data:                                                        ||~v@@@R~
      xehosts      リモートファイルアクセス用サンプルホスツファイル。 ||~v@@@R~
      xesynw.cfg   (Win)シンタックスハイライト用設定ファイル。        ||+v@@@R~
      xeebc.map    EBCDIC 変換用設定ファイル                          ||~v@@@I~
                                                                      ||~v@@@I~
  sample\staff:外部ツールを用意できない場合は以下のものをお使いください||+v@@@R~
                                                                      ||~v@@@I~
      grep.exe     コマンド行の GREp コマンド、=3.14 画面で使用します ||+v@@@R~
                                                                      ||~v@@@I~
      シンタックスハイライトで使用します、次のどちらかを選んで xesynw.cfg で指定します||+v@@@R~
        使い方は xej.txt や xesynw.cfg を見てください                 ||+v@@@R~
        gnu-source-highlight.zip                                      ||~v@@@R~
                     (Win)GNU source-highlight v2.9 を MinGW上でコンパイルしました。||~v@@@M~
        WinHighlight31.copies2.zip                                    ||~v@@@R~
                     andre simon's highlight v3.1                     ||~v@@@R~
                     exe と dll のフォルダーを離さないでください      ||~v@@@I~
      putty063.zip                                                    ||+v@@@I~
                     リモートアクセスに putty を使用する場合に必要です||+v@@@I~
                                                                      ||~v@@@I~

起動方法

  (Windows版)                                                         ||~v@@@R~

  ．ワークフォルダーを作成する、省略値はc:\xe_wdだが c:\は保護されている可能性があるので避けてください||+v@@@R~
    例えば  "mkdir d:\xe_wd"                                          ||~v@@@I~
  ．ワークフォルダーに zipファイルを置き,そこで解凍する               ||~v@@@R~
      必要に応じて sample\data フォルダーからxehosts などの設定用ファイルをワークフォルダーにコピーし修正してください||~v@@@I~
      それらの機能を使用しない場合は コメント行("#") 1行のファイルにしてください||~v@@@I~
  . 実行可能ファイルに PATH を通す.                                   ||+v@@@R~
      Windows10の場合、コントロールパネル-->システムとセキュリティ-->システム-->システムの詳細設定-->環境変数:PATH||~v@@@I~
  . ワ－クディレクトリー名を環境変数:xe にセットする                  ||~v@@@R~
      あるいは 任意に作成した xe 起動用コマンドファイルを作成する     ||~v@@@R~
      例えば xe.bat                                                   ||~v@@@I~
               set xe=d:\xe010                                        ||~v@@@R~
               xe.exe                                                 ||~v@@@I~
            あるは                                                    ||~v@@@I~
               xe.exe /wd:\xe010                                      ||~v@@@I~
  ．xe [ファイル名] で起動する
      コマンドライン パラメータは  xe /? で表示されます               ||~v@@@R~
  . wxe も同じです                                                    ||~v@@@I~
                                                                      ||~v@@@I~
  (Linux版)                                                           ||~v@@@I~
  .ターミナルエミュレーターを開き、適当な場所で解凍しconfigure/make/install||~v@@@R~
      tar -zxvf gxe-1.xx.tar.gz                                       ||~v@@@I~
      cd                                                              ||~v@@@I~
      ./configure                                                     ||~v@@@I~
      make                                                            ||~v@@@I~
      sudo make install   -->/usr/local/binにインストール             ||~v@@@R~
    問題が発生したらsampleフォルダーの READMEj.txt を参照してください ||~v@@@I~
    必要なら/usr/local/binにインストールされないコマンドラインツールは||~v@@@I~
    src/xsub フォルダーから手動でコピーしてください                   ||~v@@@I~
  .ワークフォルダーを home に作成                                     ||~v@@@I~
      mkdir ~/xe_wdnnnnn     nnnnn は ユーザーID番号                  ||~v@@@I~
    必要に応じて sample フォルダーからxehosts などの設定用ファイルをワークフォルダーにコピーし修正してください||~v@@@I~
    それらの機能を使用しない場合は コメント行("#") 1行のファイルにしてください||~v@@@I~
  ．xe [ファイル名] で起動する                                        ||~v@@@I~
      コマンドライン パラメータは  xe -? で表示されます               ||+v@@@R~
      F1、F10 や 修飾キー(Shift/Alt/Ctrl)との組み合わせはターミナルエミュレーターで||~v@@@I~
      ショートカットキーに設定されている場合があります                ||~v@@@I~
      xe で F1、F10 などを使用する場合ターミナルエミュレータの設定でショートカットを無効にする必要があります||+v@@@R~
  . gxe はターミナルエミュレータのショートカットキーの影響はありません||~v@@@R~
                                                                      ||~v@@@I~
######################################################################
修正履歴.
  .v010 (95/06/04)
        初版                                                          
######################################################################
  .v129A<--129:(2017/06/24)

     1.BUGs
       -(Windows:64)"&"(バイナリーファイル非同期実行) ディレクトリーリストコマンドがクラッシュする
       -(64Bit) =3.14 がクラッシュする

     3.その他
       -(Windows)拡張子:"msi" を実行可能ファイルの拡張子に追加
