||*CID:||+129FR~:  2018/01/23                update#=  804;           ||+129FR~
######################################################################
[Japanese]    v1.29F                                                  ||+129FR~

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
                                                                      ||~129DI~
  .v129C<--129B:(2017/09/04)                                          ||~129DI~
                                                                      ||~129DI~
     1.BUGs                                                           ||~129DI~
                                                                      ||~129DI~
     2.機能追加                                                       ||~129DI~
       -Find コマンド                                                 ||~129DI~
          ディレクトリーリスト上で ATTR(属性)欄のみを探すオプションを追加||~129DI~
          大文字小文字の区別はしません                                ||~129DI~
          属性欄には表示されていないが ディレクトリーには "d"、シンボリックリンクには "L" を指定する||~129DI~
          また "d" と "L" はそれぞれ単独で指定してください            ||~129DI~
          それ以外の属性は Windowsでは 指定の一つ一つの属性すべてを含む行が一致行とし||~129DI~
          Linuxでは属性指定の文字列を含む行が一致行とする             ||~129DI~
          Linuxで特殊な属性欄の値は                                   ||~129DI~
            u:setuid, g:setgid, S:setuid+setgid, t:stickey            ||~129DI~
            c:char device, b:block device, p:pipe, s:socket           ||~129DI~
        例) (Windows) f SH attr ; f R attr & 17-08 ; f D attr & L attr||~129DI~
            (Linux)   f 775 attr ; f u attr                           ||~129DI~
                                                                      ||~129DI~
     3.その他                                                         ||~129DI~
       -(Windows)ICU EBCDIC変換ライブラリーlibicuuc.dllが見つからないとき||~129DI~
        xeebc.mapに ICU_DATA の指定があればそのフォルダー内もチェックする||~129DI~
        なければ 環境変数 ICU_DATA もチェックする                     ||~129DI~
        (Linux)/usr/lib など以外にある場合は LD_LIBRARY_PATH 環境変数に ICU の so のパスをしてしてください||~129DI~
       -xeebc.map に ICU_DLL_SUFFIX, ICU_APP_SUFFIX が ないとき       ||~129DI~
        ICU の uconv(.exe) で ICU のバージョンが分かればそれを補う    ||~129DI~
       -CPU8(UTF8)ファイルではレコード長は不定なので/Mr(レコードモード)オプションは受け付けない||~129DI~
                                                                      ||~129DI~
     4.ツール。                                                       ||~129DI~
       -xprint v9.38                                                  ||~129DI~
        ./Tabon: パラメータサポート追加                               ||~129DI~
           DBCSスペース、TAB(0x09)とそれに続く桁空けに表示する代替文字を指定する||~129DI~
           /Tabon:x:y:z ;テキストモードのときのDBCSスペース,タブ文字,タブスキップの||~129DI~
                        ;代替印刷文字。x,y,zは 文字、ヘキサ文字またはユニコード。||~129DI~
                        ;例) /Tabon:x2020:x18:x1a  /Tabon::u2191:u2192 /Tabon::u25cb||~129DI~
                        ;    /Tabon:u2750                             ||~129DI~
                        ;省略値は UTF8/EBCDICファイル /Tabon:u3000:x20:x20||~129DI~
                        ;                        以外 /Tabon:x8140:x20:x20||~129DI~
        .EBCDIC ファイルを ICU で変換して印刷するときで /BCfilename の指定がない場合||~129DI~
         ICU の 共有ライブラリー(DLL または so)が PATH または LD_LIBRARY_PATH にあれば||~129DI~
         探して ICU バージョンは uconv(.exe) を発行して それを補う    ||~129DI~
           例) xprint x1ebc22 -cpeb=cp930 -me -icu                    ||~129DI~
       -xcv 1.20                                                      ||~129DI~
        .EBCDIC ファイルを ICU で変換するときで /BCfilename の指定がない場合||~129DI~
         ICU の 共有ライブラリー(DLL または so)が PATH または LD_LIBRARY_PATH にあれば||~129DI~
         探して ICU バージョンは uconv(.exe) を発行して それを補う    ||~129DI~
           例) xcv x1ebc22 x1ebc22m -b2m -cpeb=cp930 -icu             ||~129DI~
                                                                      ||~129DI~
  .v129D<--129C:(2017/12/03)                                          ||~129DI~
                                                                      ||~129DI~
     1.BUGs                                                           ||~129DI~
       -(Linux)GTK3環境の時セットアックダイアログでのメニューアクセラレーター(Ctrl+)オプションの||~129DI~
        オン/オフが効かない                                           ||~129DI~
       -(Wxe)ファイル-New(新規ファイル)でクラッシュ                   ||~129DI~
                                                                      ||~129DI~
     2.機能追加                                                       ||~129DI~
       -SelectAll                                                     ||~129DI~
          .コマンド                                                   ||~129DI~
             SEL [all] [col1 col2] [.label1 .label2]                  ||~129DI~
               label1/2 で行範囲指定、col1/2 でカラム範囲指定         ||~129DI~
               labelは1/2とも数字による行番号指定でもよい             ||~129DI~
               col の指定があるとブロックモード、ないと領域モード     ||~129DI~
               label/column の指定がないと全選択                      ||~129DI~
               例）sel; sel .a .b; sel 1 20; sel 10 20 .1 .4;         ||~129DI~
          .Edit画面で 行選択し、Cut/Copy/Pasteにつなげていきます      ||~129DI~
           領域モードではすぐPaste の対象にもなります                 ||~129DI~
        (Wxe,gxe)                                                     ||~129DI~
          .Editサブメニュー、ポップアップメニューにも "SelectAll" メニュー項目追加||~129DI~
          .ショートカットはCtrl+Aに設定 SaveAs(別名保存)はCtrl+Shift+Aに変更||~129DI~
                                                                      ||~129DI~
     3.その他                                                         ||~129DI~
       -Fileサブメニューのメニュー項目も画面の状況によっては不活性化する||~129DI~
        例えば、ディレクトリー画面での保存メニュー項目など            ||~129DI~
                                                                      ||~129DI~
  .v129E<--129D:(2018/01/09)                                          ||~129DI~||~129ER~
                                                                      ||~129DI~
     1.BUGs                                                           ||~129DI~
                                                                      ||~129EI~
       -Window コンソール版：ヘッダー行のエラーメッセージが文字化けすることがある||~129EI~
                                                                      ||~129DI~
     2.機能追加                                                       ||~129DI~
       -XMLタグ ペア探索                                              ||~129DI~
          .デフォルトで Alt+"/" を割り当て                            ||~129DI~
          .カーソルを "<" または ">" の位置において "Alt+/" を使用    ||~129DI~
          .コメントない("<!--" から "-->")は無視、ネストも処理、      ||~129DI~
           html 自動生成ツールの不具合を修正するのに便利です          ||~129DI~
                                                                      ||~129DI~
     3.その他                                                         ||~129DI~
                                                                      ||~129DI~
       -Window コンソール版：Windows10ではリガチャー:ONにすると UTF8 ファイルの||~129EI~
        DBCS 表示が桁ずれするので Windos7以降 コンソール版ではリガチャー:ONを受け付けない||~129EI~
                                                                      ||+129FI~
  .v129F<--129E:(2018/01/23)                                          ||+129FI~
                                                                      ||+129FI~
     1.BUGs                                                           ||+129FI~
                                                                      ||+129FI~
       -Edit/Browse コマンド                                          ||+129FI~
        .レコードモードでレコードサイズ>4096かつ最初のレコードに制御文字(<0x20)があると||+129FI~
         最後のレコードのみが表示される。またファイルサイズが128K超だとクラッシュする||+129FI~
        .レコードモードの時プロファイルに記録したのCPLCが無視される（毎回CPLCの指定が必要になる)||+129FI~
                                                                      ||+129FI~
