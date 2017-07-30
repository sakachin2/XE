||*CID:||+129BR~:  2017/06/24                update#=  797;           ||+129BR~
######################################################################
[Japanese]    v1.29B                                                  ||+129BR~

メインフレーム(SPFファイルの編集にも便利) と PC と 両方仕事している人に使い易いエディター。
ホストのSPFをベースにPCのEDITORの便利なキー操作をハイブリッド。

    .Windows版、Linux版あり
    .改行コードなしの固定長レコード/可変長ファイルサポート。
    .UTF8ファイル、EBCDIC(ICUの導入が必要)ファイル編集。
    .バイナリーエディター(縦2段HEXか横HEX表示）
    .ファイラー(フォルダー表示、削除、改名、複写、実行...)
    .リモートアクセス。
       ftp,samba,rsh,ssh,fuse
    .オプションで変更行に修正タグを自動付与。

  ライセンス:GNU GPL に従う。

                                   By 水巻マチ (sakachin2@yahoo.co.jp)

                                   http://hp.vector.co.jp/authors/VA010562
                                   http://www.geocities.jp/sakachin2/index.htm
                                   GitHub: sakachin2/XE

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
    ワークディレクトリーに置くか、xehelp環境変数
    あるいは/hdコマンドラインパラメータで位置指定する。
    Linux版でのこれ以外の置き場所はxelnxj.txtを参照してください
  sample\doc:
    テキストファイル形式のマニュアル
      xej.txt/xee.txt
      xereadmj.txt/xereadme.txt
      xelnxj.txt/xelnxe.txt(Linux版用)
      xewxej.txt/xewxee.txt(GUI版:wxe/gxe用)
  sample\data:
      xehosts      リモートファイルアクセス用サンプルホスツファイル。
      xesynw.cfg   (Win)シンタックスハイライト用設定ファイル。
      xeebc.map    EBCDIC 変換用設定ファイル

  sample\staff:外部ツールを用意できない場合は以下のものをお使いください

      grep.exe     コマンド行の GREp コマンド、=3.14 画面で使用します

      シンタックスハイライトで使用します、次のどちらかを選んで xesynw.cfg で指定します
        使い方は xej.txt や xesynw.cfg を見てください
        gnu-source-highlight.zip
                     (Win)GNU source-highlight v2.9 を MinGW上でコンパイルしました。
        WinHighlight31.copies2.zip
                     andre simon's highlight v3.1
                     exe と dll のフォルダーを離さないでください
      putty063.zip
                     リモートアクセスに putty を使用する場合に必要です


起動方法

  (Windows版)

  ．ワークフォルダーを作成する、省略値はc:\xe_wdだが c:\は保護されている可能性があるので避けてください
    例えば  "mkdir d:\xe_wd"
  ．ワークフォルダーに zipファイルを置き,そこで解凍する
      必要に応じて sample\data フォルダーからxehosts などの設定用ファイルをワークフォルダーにコピーし修正してください
      それらの機能を使用しない場合は コメント行("#") 1行のファイルにしてください
  . 実行可能ファイルに PATH を通す.
      Windows10の場合、コントロールパネル-->システムとセキュリティ-->システム-->システムの詳細設定-->環境変数:PATH
  . ワ－クディレクトリー名を環境変数:xe にセットする
      あるいは 任意に作成した xe 起動用コマンドファイルを作成する
      例えば xe.bat
               set xe=d:\xe010
               xe.exe
            あるは
               xe.exe /wd:\xe010
  ．xe [ファイル名] で起動する
      コマンドライン パラメータは  xe /? で表示されます
  . wxe も同じです

  (Linux版)
  .ターミナルエミュレーターを開き、適当な場所で解凍しconfigure/make/install
      tar -zxvf gxe-1.xx.tar.gz
      cd
      ./configure
      make
      sudo make install   -->/usr/local/binにインストール
    問題が発生したらsampleフォルダーの READMEj.txt を参照してください
    必要なら/usr/local/binにインストールされないコマンドラインツールは
    src/xsub フォルダーから手動でコピーしてください
  .ワークフォルダーを home に作成
      mkdir ~/xe_wdnnnnn     nnnnn は ユーザーID番号
    必要に応じて sample フォルダーからxehosts などの設定用ファイルをワークフォルダーにコピーし修正してください
    それらの機能を使用しない場合は コメント行("#") 1行のファイルにしてください
  ．xe [ファイル名] で起動する
      コマンドライン パラメータは  xe -? で表示されます
      F1、F10 や 修飾キー(Shift/Alt/Ctrl)との組み合わせはターミナルエミュレーターで
      ショートカットキーに設定されている場合があります
      xe で F1、F10 などを使用する場合ターミナルエミュレータの設定でショートカットを無効にする必要があります
  . gxe はターミナルエミュレータのショートカットキーの影響はありません

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

  .v129B<--129A:(2017/07/10)

     1.BUGs

       -(Win64) データタイプ X(Hex),O(octal) の計算結果の誤り
       -(Win64) 分割画面間のドラッグドロップ(ファイルのコピー)がクラッシュ

     2.機能追加

       -長いパス名に短縮名を定義
        .SP { edit | refresh | add sp-name { file-spec | *\\ | ^*\\ } }
            edit   : 定義ファイル(::xe.shortpath) を編集表示
                     修正して保存すれば、次回から有効になる
                     あるいは保存後 "refresh" すれば有効になります
                     定義ファイルの各行は"短縮名 フルパス名" の形式
                     コメント行は先頭に "#"
                     例) srctest1 d:\eclipse-workspace\testproject1\src\com\debug\test
                         ecws  "c:\Program Files\Android\Android Studio\gradle"
            refresh: 定義ファイルを修正した場合に、その修正を反映させる
                     "sp edit" 画面で修正、保存後 あるいは直接 ::xe.shortpath ファイルを
                     他のプロセスで修正した後に使用する
            add    : 定義ファイルに sp-name:短縮名, file-spec:ターゲットファイル名 の行を追加
                     この定義はすぐ使用できる
                     *\ :現在開いているファイル/ディレクトリー,
                     ^*\:分割画面の他方で現在開いているファイル/ディレクトリー
                     も状況が適当ならば使用できる
                     例) sp add srctest1 d:\eclipse-workspace\testproject1\src\com\debug\test
                         sp add ecws  "c:\Program Files\Android\Android Studio\gradle"
        .短縮名は "sp:"プレフィックスで使用する
         (sp:xxx の xxx が未定義の場合はそのまま "sp:xxx" として使用される)
           例) e sp:srctest1\Main.java
               e sp:ecws
               e "sp:ecws\space embedded name"
               xcopy sp:ecdir\x1 sp.ecdir\x2
               cd sp:ecdir
