UTF8 encoding         V130A 2024/12/16

--------------------------------------------------------------------
gxe-xxx.tar.gz を "tar -zxvf" で解凍し、"./configure && make" する。
コンパイルが成功したら、make install で /usr/local/binに 導入。

--------------------------------------------------------------------
Automake パッケージ 導入手順。
--------------------------------------------------------------------

    導入先フォルダーを変更する場合は ./configure を実行する前にconfigureを修正してください。
        html ヘルプは  "packagehelpdir",                省略値は /usr/local/share/gnome/help/gxe
        icon は        "packagepixmapsdir",             省略値は /usr/local/share/pixmaps/gxe
        bins は        ./configure --bindir=PATHで指定。省略値は /usr/local/bin

    (1)tar -zxvf gxe-v.rr.tar.gz    (v.rr : version)
    (2)cd gxe-v.rr
    (3)./configure
    (4)make
    (5)make install (rootで実行、ubuntuでは "sudo make install")
       次のbinだけが導入されます。これ以外のツールは自分でコピーしてください。
         gxe, xe, xprint, gxp, xfc, xdc
    (6)gnome-terminal ないし konsole 等の terminal emulator を開いて gxe ないし xe と入力する。
       ヘルプhtmlは立ち上げ後 第2行に "help" ないし "?" を入力するとブラウザーから観ることが出来ます。
    (7)ssh
       リモートでxe起動する場合、ssh(d)の設定をチェック。
           local :/etc/ssh/ssh_config
                      set "SendEnv LANG LC_*"
           remote:/etc/ssh/sshd_config
                      set "AcceptEnv LANG LC_*"
                      set "X11Forwarding yes"
                      xhost +local:username    local=local ip addr, username=your user id
                  xauth は導入済みか ?

       リモートでgxe起動する場合 -X オプションを指定する。
           ssh -X uid@remotehost
    (8)ショートカットキーの変更。(PF10 等が terminal emulator をパスしてxeに伝わるようにする)
       例えば Debian jessie 3.10 xfce では
    	ショートカットキー変更 F1=ヘルプ, F11=全画面, F10=メニュー
        	xfce4-terminal のメニューで
            	ヘルプ-->目次("F1" が表示されている)メニュー項目の上で"Del"キーを押す
            	表示-->全画面表示("F11"が表示されている)メニュー項目上で"Del"を押す
                編集-->設定(E)-->上級者(V), "メニューショートカットキーを無効にする"をオンにする

--------------------------------------------------------------
トラブルシューティング
--------------------------------------------------------------
導入トラブル
--------------------------------------------------------------
  (Q) Linux Mint 22                     2024/12/11
      ./configure
          -->"FATAL:term.h not found. Install ncurses-devel."
         (    
            sudo apt install apt-file
            sudo apt-file update
            sudo apt --upgradable
            sudo apt upgrade
         )
         ==>apt-file find term.h | grep curses
            --> libncurses-dev: /usr/include/ncursesw/term.h
         ==>sudo apt install libncurses-dev

      ./configure
          -->cups/cups.h Not Found
          ==>apt-file find cups/cups.h
             -->libcups2-dev: /usr/include/cups/cups.h
          ==>sudo apt install libcups2-dev

      ./configure
          -->install GTK3 or GTK2
          ==>apt-file find gtk+-3.0
             -->libgtk-3-dev: /usr/lib/x86_64-linux-gnu/pkgconfig/gtk+-3.0.pc
          ==>sudo apt install libgtk-3-dev

      ./configure
          -->(done)
      make
          (done)
      sudo make install
          (ls /usr/local/bin -l)

  (P) ManjaroXfce 24.0.1                 2024/06/09( gxe v1.29X )
      ./configure
          "no acceptable C compiler"
              after sudo pacman -Fy
              pacman -F gcc
              sudo pacman -S gcc
      ./configure
          "pkg-config was not found"
              pacman -F pkg-config
              sudo pacman -S pkgconf     (!! not pkg-config but pkgconf)
      ./configure
           "ncursesw/ncurses.h not found"
      ./configure --enable-ncursesw=no
           "Something went wrong ... configure MAKE="qmake" ..."
              sudo pacman -S make
      ./configure --enable-ncursesw=no
           (done)
      make
          (done)
      sudo make install
          (ls /usr/local/bin -l)
      adjust xfce4-terminal setting; shortcut tab: remove F1, F10, F11, Shft+PgUp, Shift+PGDn, ...
                                     detaile tab: disable emanu-shortcut(F10).

  (N) Kubuntu24.04                       2024/06/01( gxe v1.29X )
          "term.h is not found"
              (
                sudo apt install apt-file
                sudo apt-file update
              )
              apt-file find term.h | grep ncurses
              ==> sudo apt install libncurses-dev
          "cups/cups.h is not found"
              apt-file find cups.h
              ==> sudo apt install libcups2-dev
          "libglib2 is required if libgnome2 is not installed"
              apt-file find gio/gio.h
              ==> sudo apt install libglib2.0-dev
          "install GTK2 or GTK3"
              apt-file find gtk.h | grep libgtk
              ( select GTK3, GTK2 development was stopped at 2011 )
              ==> sudo apt install libglib-3-dev

  (M) V129U (--enable-libgnome2=no is now not required)

  (L) v129T

  (L1)./configure でのトラブル。debian11 の場合(2022/12/04)

          configure: error: in `/home2/Projects/gxeinsttestdebian/gxe-1.29':
          configure: error: no acceptable C compiler found in $PATH

              ===>apt-get install gcc

          configure: error: "FATAL:term.h not found. Install ncurses-devel."

              ===>apt-file search tearm.h |grep curses
              ===>apt-get install libncurses-dev

          configure: error: "FATAL:cups/cups.h not found. Install cups-devel."

              ===>apt-file search cups/cups.h
              ===>apt-get install libcups2-dev

          configure: error: install GTK2(>=2.10.0) or GTK3(>=3.4.0) if NOT enable-gxe=no.

              ===>apt-file search /gtk.h
              ===>apt-get install libgtk-3-dev

          configure: error: !!! libgnome-2.0 installation required, OR specify --enable-libgnome2=no with glib-2.0 gio-2.0 installed.

              ===>./configure enable-libgnome2=no

          make: command not found

              ===>apt-get install make

  (K) Fedora33                          2020/12/09 
          missing term.h ==>yum install ncurses-devel
          missing cups/cups.h ==> yum install cups-devel
          install GTK2 or GTK3 ==>yum install gtk3-devel
          install libgnome2 OR --enable-libgnome2=no with glib2.0 installed
                  ==>./configure --enable-libgnome2=no ==>completed succssfully.
                  (glib2.0(including gio.h) is installed by dependency of gtk3-devel)
          Check it that gio.h is refered by "pkg-config --cflags glib-2.0"
  (J) Manjaro gnome 20.1.2              2020/10/23 
           C compile not found          ==> pacman -S gcc
           ncursesw/ncurses.h not found ==> ./configure --enable-ncursesw=no
           pkg-config not found         ==> pacman -S pkg-config
           lingnome-2 required          ==> ./configure --enable-libgnome2=no
           correct make to qmake        ==> packman -S make

           console version Backspec dose not word ==>  specify --7 option "xe --7B"
                    OR on Preference dialog, assign Ctrl-H to backspace, ASCII DEL to Delete key.

  (I) Rspberry PI  2020/05/16
     configure エミュレーターでテストしました（image:"2020-02-13-raspbian-full" on QEMU3.1.0）
       ./configure で以下のエラーがありました
          term.h not found
          -->#apt-get install libncurses-dev
          cups/cups.h not found
          -->#apt-get install libcups2-dev
          install GTK2 or GTK3
          -->#apt-get install libgtk-3-dev
          select libgnome2 or glib-2.0
          -->#apt-get install glib-2.0
          ==>./configure 成功

--------------------------------------------------------------
実行時トラブル
--------------------------------------------------------------

    (1)  WARNING **:Could'nt find pixmap file gxe/wxe.png
        ===> "make install" を root で実行. (A)の導入先フォルダーをチェック。

    (2) WARNING **: IPP request failed with status 1030
        ===> CUPS プリンターをセットアップする。プリンターがつながってない場合でも何か設定する。

    (3) WARNING **: IPP request failed with status 1280
        ===> CUPS サービスデーモンを開始.

    (4) ??? xe:serach for gnome-terminal by "which" cmd failed ???
        ===> "xe: use konsole for shell terminal" が続いていれば問題ない。
             そうでなければ gnome-terminal か konsole を導入する。

    (5) Gdk-WARNING **: gdk_property_get(): length value has wrapped in calculation (did you pass G_MAXLONG)
        ===> 無視.
             (imlib call gdk_property_get with length=MAX_INT,callee issue warning length+3>G_MAXLONG,then use G_MAXLONG as length.)

    (6) WARNING **: failed request with status 200
        ===> 無視.
             理由は分からないが無害のようだ。

    (7) GnomePrintCupsPlugin-WARNING **: failed iconv dose not support ppd character encoding: ISOLatin1, trying CSISOLatin1
        ===> 無視.
             理由は分からないが無害のようだ。

    (8) WARNING ***: Owner of /tmp/xx-username is not the current user
                     Failed to initialize Panel Agent!
        ===> UserID 番号 を変更した。 表示されたフォルダーを削除。
             旧 UserIDの /tmp/scim-panel-socket-username... も削除。

    (9) GnomePrint-CRITICAL ... assertion face != NULL failed
        ===> 印刷フォント名にフェイス名(Regular,Bold,Italic など) がかけている。
             xeは最初画面フォント名から印刷フォント名を設定するがxeはこのケースの時Regularを補完するので
             以降は出ないはず。

    (10) xe help command 失敗
         (MIME タイプ text/htmlに省略時アクション(ブラウザーの起動)が定義されていない。
          Gnome デスクトップの場合それは /usr/share/mime-info/gnome-vfs-keys にある)
        ===> install desktop-file-utils
             /usr/share/applications/defaults.list-->/etc/gnome/defaults.list is installed.

    (11) Gtk WARNING : Cannot open display   (Debian 4.0 when started from console)
        confirm  xauth("apt-get install xauth" on Debian9.3) is installed
        (check also environment variable DISPLAY= on remote)
        chk ssh option "ssh -X"
        X11Forwarding=yes on ssh.config(local)/sshd.config(remote)

    (12) Gtk WARNING : Locale not supported by C library at debian/390
        ===>"setlocale" が失敗する場合 locale を追加する。
                 "locale -a" で使用可能なlocale をチェック、リストになければ
                 "dpkg-reconfigure locales"

    (13)文字化け(debian/390)
        ===>unifont を導入
                "aptitude install unifont"

    (14)Gconf err, scim failed to load frontend module
        ===>rootユーザーで gxe を起動している。そして /root/gconf(d) がない。
            "su" ではなく "su -"  でrootになる。sudo なら "sudo -i"

    (15)"(スーパーユーザで)" がタイトルに出る。
        s390xに "ssh -X" して X-applを起動した時。
        ===>無視。権限はrootになっていない。
            metacity というパッケージが出しているらしいが、X-サーバー(local側のdaemon）が
            root だからではないかと思う。

    (16)ssh の X-APPL で文字化け。(s390x)
        sshのロケールは /etc/ssh/ssh(d).conf の AcceptEnv/SendEnvで local のロケールを 
        継続することが出来、ssh上は日本語表示されるが、
        Xappl用には導入が必要らしい
        ===> yum install "@Japanese Support" あるいは yum groupinstall "Japanese Support"

    (17)"Gtk WARNING ** cannnot open display"
        ==> "export DISPLAY=localhost:10.0"   (10 may be 11, 12..., リモートのsshd_config:X11DisplayOffset(省略値:10)を確認)
        "su" するとでる。通常は DISPLAY は ssh が自動で割り当てる。
        通常DISPLAYはsshが制御するので必要ないはずだが
        リモートにxauth は導入済みか?

	(18)WARNING **: Couldn't register with accessibility bus: Did not receive a reply. Possible causes include: the remote application did not send a reply, the message bus security policy blocked the reply, the reply timeout expired, or the network connection was broken.
        -->export NO_AT_BRIDGE=1 で環境変数を設定する

    (19)Gtk-WARNING **: Calling IsInhibited failed: GDBus.Error:org.freedesktop.DBus.Error.ServiceUnknown: The name org.gnome.SessionManager was not provided by any .service files
        -->無害なので無視する
--------------------------------------------------------------
リモートアクセス
--------------------------------------------------------------
(D) sshfs の導入

   .sshfs をパッケージマネージャを使って導入する。
   .fusermountに実行権限があるか確認する、なければ chmod +x /usr/bin/fusermount. 
   .マウントポイントを 777 で 作る  (mkdir /mountpoint; chmod 777 /mountpoint)
   .使用するユーザーＩＤを グループ fuse のメンバーにする。reboot が必要.
   ./dev/fuseのオーナーグループがfuseになっているか確認、そうでなければ chgrp fuse /dev/fuse。 

   使用法:
     sshfs [-o uid=nnn] [-o gid=nnn] user@remotehost:/remotedir /mountpoint
   
     Windows版のDokan sshfs は GUIでドライブＩＤを割り当てるようになっているので。
     "e N:\"のようにアクセスする。

