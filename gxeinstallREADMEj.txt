UTF8 encoding

V130B 2025/01/17

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
  (S) s390x                             2025/01/15
      local:ubuntu24.04    remote:ubuntu18.04(s390x) on SDL hercules 4.7
###
    (upload xe)
		src=/home2/Projects/gxe/gxe-1.30.tar.gz
		dest=10.1.1.2
		tgt=/home/sak
		scp $src sak@$dest:$tgt

  		ssh sak@10.1.1.2
		tar -zxvf gxe-1.30.tar.gz
		cd gxe-1.30
		export LANG=C
###
    (make)
        ./configure
        -->
            configure: error: no acceptable C compiler found in $PATH
        ==>
            sudo apt-get install gcc
#
        ./configure
        -->                                                                         
            configure: error: "FATAL:term.h not found. Install ncurses-devel."
        ==>
            apt search ncurses
            -->
                libncursesw5-dev/bionic-updates,bionic-security 6.1-1ubuntu1.18.04.1 s390x
        ==>
            sudo apt install libncursesw5-dev
#
        ./configure
        -->                                                                         
            configure: error: "FATAL:cups/cups.h not found. Install cups-devel."
        ==>
            apt search cups
            -->                                                                         
                libcups2-dev/bionic-updates,bionic-security 2.2.7-1ubuntu2.10 s390x
        ==>
            sudo apt install libcups2-dev
#
        ./configure
        -->                                                                         
            configure: error: "FATAL:glib.h and gio/gio.h is not found,
            it is required if libgnome2 is not installed. Install glib2.0-dev"
        ==>
            apt search glib2
            -->                                                                         
                libglib2.0-dev/bionic-updates,bionic-security 2.56.4-0ubuntu0.18.04.9 s390x
        ==>
            sudo apt install libglib2.0-dev
#
        ./configure
        -->                                                                         
            checking for gtk+-3.0... no
            checking for gtk+-2.0... no
            configure: error: install GTK2(>=2.10.0) or GTK3(>=3.4.0) if NOT enable-gxe=no.
        ==>
            apt search gtk-3
            -->                                                                         
                libgtk-3-dev/bionic-updates 3.22.30-1ubuntu4 s390x
        ==>
            sudo apt install libgtk-3-dev
#
        ./configure
        -->                                                                         
            done
#
		make 
		sudo make install   (to /usr/local/bin as default)
###
    (execution)
		remote 10.1.1.2    ubuntu 18.04-s390x:x11
		local  192.168.1.7 ubuntu 24.4       :Wayland(Xwayland)
        (Note) ssh-client's Xwayland of Wayland supports communication with remote ssh-server's x11-client.
               confirm it on ssh client(ubuntu 24.4)
			       ps -ef|grep -i xwayland
                   -->
			       sak         2845    2435  0 10:53 ?        00:00:01 /usr/bin/Xwayland :0 -rootless -noreset -accessx -core -auth /run/user/1000/.mutter-Xwaylandauth.3F06Z2 -listenfd 4 -listenfd 5 -displayfd 6 -initfd 7 +byteswappedclients
			       (This line indicate byteswappable by +byteswappedclients)
#
    	ssh sak@10.1.1.2
		xe
    	-->
			Unable to init server: could not connect: connection refused
			Gtk-WARNING **: 18:16:21.700: cannot open display:
#
    	ssh -X sak@10.1.1.2
        (
            -X:forward x11, -Y:forward x11 trusted
         OR
            at local(ssh client)
                /etc/ssh/ssh_config
                    ForwardX11   yes       # ssh -X
                    ForwardX11Trusted yes  # ssh -Y
        )
		xe
    	-->
			Unable to init server: could not connect: connection refused
			Gtk-WARNING **: 18:16:21.700: cannot open display:
#
		at remote also required to forward x11.
		sudo nano /etc/ssh/sshd_config
        	X11Forwarding   yes
        sudo systemctl restart sshd

    	ssh -X sak@10.1.1.2
		xe
    	-->
			Prohibited client endianess, see the Xserver man page Unable to init server: Could not connect: Connection refused
			(xe:1020): Gtk-WARNING **: 10:37:12.045: cannot open display: localhost:10.0
#
		at ubuntu24
	    	$ gsettings get org.gnome.mutter.wayland xwayland-allow-byte-swapped-clients
    		$ gsettings set org.gnome.mutter.wayland xwayland-allow-byte-swapped-clients true

    	ssh -X sak@10.1.1.2
		xe
    	-->
			Prohibited client endianess, see the Xserver man page Unable to init server: Could not connect: Connection refused
			(xe:1020): Gtk-WARNING **: 10:37:12.045: cannot open display: localhost:10.0
#
		at ubuntu24(ssh server)
    		add or update the following section in xorg.conf or add new xxx.conf file in xorg.conf.d
    			/etc/X11/xconf.conf  OR /etc/X11/xconf.org.d/endian.conf
		    		Section "ServerFlags"
       				Option "AllowSwappedClients" "on"
    				EndSection
        	reboot
        	(
				ps -ef will show Xwayland option of  "+byteswappedclients"
        	)
    	ssh -X sak@10.1.1.2
		xe
    	-->OK
    	(
     	Note.
        	1. if using ssh by putty, setting "export DISPLAY=localhost:10.0" may be required.
            	if yet error messag as following
					Gtk-WARNING **: 18:16:21.700: cannot open display:

                  echo $DISPLAY
                    It may be OK if it is set.
                OR
				  env|grep SSH
					SSH_CONNECTION=10.0.2.2 57211 10.0.2.15 22
					SSH_CLIENT=10.0.2.2 57211 22
					SSH_TTY=/dev/pts/1
                  ==> 
                  	export DISPLAY=10.0.2.2:0.0
        	2. to pass SSH server's Fontname to remote(X client).
            	at local
            		xeGetFont.sh
                	-->
						xeGetFont.sh 2024/06/10
						Info! font[Tlwg Typo 16] is of "gnome-terminal", default profile[b1dcc9dd-5262-4d8d-a863-c897e6d979b9].
						Tlwg Typo 16
	        		ssh -t user@host XEFONT=\"Tlwg Typo 16\" bash
            	at remote (the font may not available in remote.)
					xe  "-F$XEFONT"
        	3. Not worry about ambiguous char display width and to wish for quick start of xe.
            	at remote
					xe  -Fnone  (Not GUI app bypassing GTK init)
    	)

###
		gxe
    	-->
			(gxe:1776): IBUS-WARNING **: 11:34:22.173: The owner of /home/sak/.config/ibus/bus is not sak!
#
		sudo chown sak:sak .config/ibus/bus
		gxe
    	-->
			Info:uses "gnome-terminal" as terminal program
			Warning(gxe):No default printer, is cupsd runnung?
        OK
###
		sudo xe
    	-->
			xeGetFont.sh 2024/06/10
			Warning! terminal is other than gnome-terminal, konsole, xfce4-terminal.
			Warning! assumed "Monospace", specify -Ffontname parameter if it is not valid.
			Terminal font "Monospace" was detected

			dbind-WARNING **: 11:42:08.346: Couldn't connect to accessibility bus: Failed to connect to socket /run/user/1000/at-spi/bus: No such file or directory
    	(
     		Maybe harmfull, ignore dbind-WARNING,
     		but try this.
				sudo NO_AT_BRIDGE=1 xe
    	)
###
		sudo gxe
    	-->
			dbind-WARNING **: 12:05:44.695: Couldn't connect to accessibility bus: Failed to connect to socket /run/user/1000/at-spi/bus: No such file or directory

			IBUS-WARNING **: 12:05:52.135: The owner of /home/sak/.config/ibus/bus is not root!
			Info:uses "gnome-terminal" as terminal program

			Warning(gxe):No default printer, is cupsd runnung?
			Home directory not accessible: Permission denied
			Home directory not accessible: Permission denied
			Info:uses "gnome-terminal" as terminal program
#
		sudo NO_AT_BRIDGE=1 gxe
    	-->
			IBUS-WARNING **: 12:18:31.885: The owner of /home/sak/.config/ibus/bus is not root!
			Info:uses "gnome-terminal" as terminal program

			Warning(gxe):No default printer, is cupsd runnung?
			Home directory not accessible: Permission denied
#
	GDK_BACKEND=x11 gxe
    -->
		Info:uses "gnome-terminal" as terminal program
		Warning(gxe):No default printer, is cupsd runnung?
#
		sudo GDK_BACKEND=x11 gxe
    	-->
			dbind-WARNING **: 12:38:06.664: Couldn't connect to accessibility bus: Failed to connect to socket /run/user/1000/at-spi/bus: No such file or directory
			IBUS-WARNING **: 12:38:09.881: The owner of /home/sak/.config/ibus/bus is not root!
			Info:uses "gnome-terminal" as terminal program
			Warning(gxe):No default printer, is cupsd runnung?
			Home directory not accessible: Permission denied
#
		sudo GDK_BACKEND=x11 NO_AT_BRIDGE=1 gxe
    	-->
			IBUS-WARNING **: 12:40:44.735: The owner of /home/sak/.config/ibus/bus is not root!
			Info:uses "gnome-terminal" as terminal program
			Warning(gxe):No default printer, is cupsd runnung?
			Home directory not accessible: Permission denied
        OK

  (R) Debina 12                         2024/12/17
      ./configure
      ==>configure: error: no acceptable C compiler found in $PATH
      apt-file find bin/gcc
      ==>gcc: /usr/bin/gcc 
      sudo apt install gcc
      ==>configure: error: "FATAL:term.h not found. Install ncurses-devel."
      apt-file find include/term.h
      ==>libncurses-dev: /usr/include/term.h
      sudo apt install libncurses-dev
      ./configure 
      ==>configure: error: "FATAL:cups/cups.h not found. Install cups-devel."
      apt-file find cups/cups.h
      ==>libcups2-dev: /usr/include/cups/cups.h 
      sudo apt install libcups2-dev
      ./configure
      configure: error: !!! pkg-config was not found, install it or set PATH environment to it !!!
      apt-file find bin/pkg-config
      ==>pkgconf: /usr/bin/pkg-config
      sudo apt install pkgconf
      ./configure 
      ==>configure: error: "FATAL:glib.h and gio/gio.h is not found,
         it is required if libgnome2 is not installed. Install glib2.0-dev"
      apt-file find gio/gio.h
      ==>libglib2.0-dev: /usr/include/glib-2.0/gio/gio.h
      sudo apt install libglib2.0-dev
      ./configure
      ==>configure: error: install GTK2(>=2.10.0) or GTK3(>=3.4.0) if NOT enable-gxe=no.
      apt-file find /libgtk-3.so
      ==>libgtk-3-0: /usr/lib/x86_64-linux-gnu/libgtk-3.so.0
         libgtk-3-0: /usr/lib/x86_64-linux-gnu/libgtk-3.so.0.2406.32
         libgtk-3-dev: /usr/lib/x86_64-linux-gnu/libgtk-3.so
      sudo apt install libgtk-3-dev
      ./configure
      [done]
      make
      [done]
      sudo make install
      [done]
      ls /usr/local/bin -la
      ==>
      total 33976
      drwxr-xr-x  2 root root    4096 Dec 17 20:13 .
      drwxr-xr-x 10 root root    4096 Dec 17 17:29 ..
      -rwxr-xr-x  1 root root 5617856 Dec 17 20:13 gxe
      -rwxr-xr-x  1 root root 2154800 Dec 17 20:13 gxp
      -rwxr-xr-x  1 root root 1750824 Dec 17 20:13 xbc
      -rwxr-xr-x  1 root root 1784424 Dec 17 20:13 xci
      -rwxr-xr-x  1 root root 1799664 Dec 17 20:13 xcv
      -rwxr-xr-x  1 root root 1816800 Dec 17 20:13 xdc
      -rwxr-xr-x  1 root root 1748128 Dec 17 20:13 xdd
      -rwxr-xr-x  1 root root 4913280 Dec 17 20:13 xe
      -rwxr-xr-x  1 sak  sak     1519 Jun 10  2024 xeGetFont.sh
      -rwxr-xr-x  1 sak  sak     1521 Jun 10  2024 xeGetFont_gnome-terminal.sh
      -rwxr-xr-x  1 sak  sak     1380 Jun 11  2024 xeGetFont_konsole.sh
      -rwxr-xr-x  1 sak  sak     1815 Jun 11  2024 xeGetFont_xfce4-terminal.sh
      -rwxr-xr-x  1 sak  sak     2250 Jun 11  2024 xeGetTerminal.sh
      -rwxr-xr-x  1 root root 2310080 Dec 17 20:13 xekbchk
      -rwxr-xr-x  1 root root 1796168 Dec 17 20:13 xfc
      -rwxr-xr-x  1 root root 1768520 Dec 17 20:13 xff
      -rwxr-xr-x  1 root root 1771040 Dec 17 20:13 xfg
      -rwxr-xr-x  1 root root 1741784 Dec 17 20:13 xpe
      -rwxr-xr-x  1 root root 2004560 Dec 17 20:13 xprint
      -rwxr-xr-x  1 sak  sak       47 Jun 29 20:00 xprint.sh
      -rwxr-xr-x  1 root root 1751984 Dec 17 20:13 xts
      ################
      xe
      ==>following error message
         Checking the font name by "xeGetFont.sh".
         xeGetFont.sh 2024/06/10
         Warning! no default profile and no font setting.
         Error! Font not found. Defult profile=.
         Terminal font "" was detected
         Font parm("") is unknown font name.

      gnome-terminal Menu button-->Settings(P)
      Settings dialog
          [Font]
              Character Tab, checkbox Font ON, update Fontface
          [shortcut]
              F10: General F10(M)
              F11: Shortcut fullscreen(F11) disable by Backspace key 
          close dialog

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
