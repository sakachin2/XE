V130A 2024/12/16

open by "tar -zxvf gxe-xxx.tar.gz", then run "./configure && make".
After successfull compilation, run "make install" to copy bin toで /usr/local/bin.

--------------------------------------------------------------------
Automake package installation step
--------------------------------------------------------------------

    If you change the installation folder, modify the configure before running ./configure.
        packagehelpdir   :html help install dir     (Default=/usr/local/share/gnome/help/gxe)
        packagepixmapsdir:icon image install dir    (Default=/usr/local/share/pixmaps/gxe)
        ./configure --bindir=PATH  for bin dir      (Default=/usr/local/bin)

    (1)tar -zxvf gxe-v.rr.tar.gz    (v.rr : version)
    (2)cd gxe-v.rr
    (3)./configure
    (4)make
    (5)make install  (by root user or "sudo make install" on ubuntu) 
       Only the following bin files will be installed. Please copy the rest of the tools yourself.
         gxe, xe, xprint, gxp, xfc, xdc
    (6)Enter gxe on command line. 
       To check help html, enter "help" or "?" on 2nd line after (g)xe started.
       Browser will show help documents.
    (6)Open a terminal emulator such as gnome-terminal or konsole and enter gxe or xe.
       After launching, you can view the help html from your browser by entering "help" or "?" on the second line.
    (7)ssh
       To execute on remote host, ssh(d) setup may be required.
           local :/etc/ssh/ssh_config
                      set "SendEnv LANG LC_*"
           remote:/etc/ssh/sshd_config
                      set "AcceptEnv LANG LC_*"
                      set "X11Forwarding yes"
                  xauth is installed ?
       To start gxe(X-appl) on remote, use -X option.
           ssh -X user@host.
    (8)Change shortcut keys (To send PF10 etc. through the terminal emulator to xe)
       For example, in Debian jessie 3.10 xfce
          Change shortcut keys: F1=Help, F11=Full Screen, F10=Menu
            In the xfce4-terminal menu
                Press the "Del" key on the Help-->Contents menu item (where "F1" is displayed)
                Press "Del" on the View-->Full Screen menu item (where "F11" is displayed)

------------------------------------------------------------------
trouble shooting.
------------------------------------------------------------------
Installation trouble.
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

  (L) V129T

  (L1)= TroubleShooting for ./configure (case of debian11. 2022/12/04).

          configure: error: in `/home2/Projects/gxeinsttestdebian/gxe-1.29':
          configure: error: no acceptable C compiler found in $PATH

              ===>apt-get install gcc

          configure: error: "FATAL:term.h not found. Install ncurses-devel."

              ===>apt-file search tearm.h | grep curses
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
error at execution.
--------------------------------------------------------------

    (1)  WARNING **:Could'nt find pixmap file gxe/wxe.png
        ===> do "make install" by root user, check also install dir of (A) above.

    (2) WARNING **: IPP request failed with status 1030
        ===> setup CUPS printer. Add any supported printer type even if you have not it.

    (3) WARNING **: IPP request failed with status 1280
        ===> start service CUPS.

    (4) ??? xe:serach for gnome-terminal by "which" cmd failed ???
        ===> This is not err if  "xe: use konsole for shell terminal" is followed.
             else install gnome-terminal or konsole.

    (5) Gdk-WARNING **: gdk_property_get(): length value has wrapped in calculation (did you pass G_MAXLONG)
        ===> Ignore.
             (imlib call gdk_property_get with length=MAX_INT,callee issue warning length+3>G_MAXLONG,then use G_MAXLONG as length.)

    (6) WARNING **: failed request with status 200
        ===> Ignore.
             I do not know why, but it may be not harmful.

    (7) GnomePrintCupsPlugin-WARNING **: failed iconv dose not support ppd character encoding: ISOLatin1, trying CSISOLatin1
        ===> Ignore.
             I do not know why, but it may be not harmfull.

    (8) WARNING ***: Owner of /tmp/xx-username is not the current user
                     Failed to initialize Panel Agent!
        ===> You changed UID number. Delete the directory in this msg.
             and /tmp/scim-panel-socket-username... of old UID.

    (9) GnomePrint-CRITICAL ... assertion face != NULL failed
        ===> This means font face name(Regular,Bold,Italic ..) is missing.
             "Regular" is appended after once change Print Font and Screen Font and save(normal exit).
             Note) xe use screen font to printScr.

    (10) xe help command fail
         (default action not defined for MIME type text/html
          On gnome desktop, it is defined in /usr/share/mime-info/gnome-vfs-keys.)
        ===> install desktop-file-utils
             /usr/share/applications/defaults.list-->/etc/gnome/defaults.list is installed.

    (11) Gtk WARNING : Cannot open display   (Debian 4.0 when started from console)
        confirm  xauth("apt-get install xauth" on Debian9.3) is installed
        (check also environment variable DISPLAY= on remote)
        chk ssh option "ssh -X"
        X11Forwarding=yes on ssh.config(local)/sshd.config(remote)

    (12) Gtk WARNING : Locale not supported by C library at debian/390
        ===>add locale if setlocale failed
                 chk by "locale -a" then
                 "dpkg-reconfigure locales"

    (13)corrupted font is dislayed at debian/390
        ===>install unifont
                "aptitude install unifont"

    (14)Gconf err, scim failed to load frontend module
        ===>You may be root user and missing files in /root/gconf(d)
            Use  not "su" but "su -"  or "sudo -i" on ubuntu to change user. 

    (15)string "(As Superuser)" is appended on title line of X-appl
        when "ssh -X" to s390x.
        ===>Ignore, No permission is changed.
            I heared that "metacity" append this.
            The reason, I think, is that X-server daemon is executing as root.

    (16)corrupted font is displayed at s390x ssh.
        ssh pass locale to remote according to AcceptEnv/SendEnv specification on /etc/ssh/ssh(d).
        ssh console show DBCS but it seems that another setup may be required for X-appl.
        ===>yum install "@Japanese Support" or yum groupinstall "Japanese Support".
            "Japanese" may be "Chinese".

    (17)"Gtk WARNING ** cannnot open display"
        ==> "export DISPLAY=localhost:10.0"   (10 may be 11, 12..., chk remote:/etc/ssh/sshd_config:X11DisplayOffset(default:10))
        You might change userid by "su" .
        Usually DISPLAY is assigned by ssh.
        xauth is installed to remote?

	(18)WARNING **: Couldn't register with accessibility bus: Did not receive a reply. Possible causes include: the remote application did not send a reply, the message bus security policy blocked the reply, the reply timeout expired, or the network connection was broken.
        -->export NO_AT_BRIDGE=1 

    (19)Gtk-WARNING **: Calling IsInhibited failed: GDBus.Error:org.freedesktop.DBus.Error.ServiceUnknown: The name org.gnome.SessionManager was not provided by any .service files
        --> Harmless, ignore it.

--------------------------------------------------------------
Remote Access
--------------------------------------------------------------
(D) sshfs installation

   .install sshfs using package manager
   .add x permission if missing (chmod +x /usr/bin/fusermount) 
   .create mount point by 777 permision  (mkdir /mountpoint; chmod 777 /mountpoint)
   .add fuse group to your userid(reboot required).
   .chk group of /dev/fuse and change the group if not yet(chgrp fuse /dev/fuse) 

   Usage:
     sshfs [-o uid=nnn] [-o gid=nnn] user@remotehost:/remotedir /mountpoint

     Dokan sshfs(Windows version sshfs) assigns driveID using GUI window.
     Access file likeas "e N:\".
