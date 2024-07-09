V130 2024/06/30

open by "tar -zxvf gxe-xxx.tar.gz", then run "./configure && make".
After successfull compilation, run "make install" to copy bin to‚Å /usr/local/bin.

--------------------------------------------------------------------
Automake package installation step
--------------------------------------------------------------------

    You may update configure before ./configure
        packagehelpdir   :html help install dir     (current=/usr/local/share/gnome/help/gxe)
        packagepixmapsdir:icon image install dir    (current=/usr/local/share/pixmaps/gxe)
        ./configure --bindir=PATH  for bin dir      (current=/usr/local/bin)

    (1)tar -zxvf gxe-v.rr.tar.gz    (v.rr : version)
    (2)cd gxe-v.rr
    (3)./configure
    (4)make
    (5)make install  (by root user or "sudo make install" on ubuntu) 

       Only following bins are installed to avoid naming contention,
       install manualy other utility as your favour.
         gxe, xe, xprint, gxp, xfc, xdc
    (6)Enter gxe on command line. 
       To check help html, enter "help" or "?" on 2nd line after (g)xe started.
       Browser will show help documents.
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
       gxe at s390
       		--> WARNING **:Couldn't connect to accessibility bus: Failed to connect to socket /tmp/dbus-xxx
       		==>export NO_AT_BRIDGE=1
------------------------------------------------------------------
trouble shooting.
------------------------------------------------------------------

  (P) ManjaroXfce 24.0.1                 2024/06/09( gxe v1.30X )
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

  (M1) on Debian11

  configure: error: no acceptable C compiler found in $PATH

  ==> apt-get install gcc

  configure: error: "FATAL:term.h not found. Install ncurses-devel."
  ==> apt-file search /term.h
      if apt-file not found
          apt-get install apt-file
          apt-file update
      fi
      apt-get install libncurses-dev

  configure: error: "FATAL:cups/cups.h not found. Install cups-devel."
  ==> apt-file search cups/cups.h
      apt-get install libcups2-dev

  configure: error: "FATAL:libglib2 is required if libgnome2 is not installed"
  ==> apt-file search libglib2
      apt-get install libglib2.0-dev

  configure: error: install GTK2(>=2.10.0) or GTK3(>=3.4.0) if NOT enable-gxe=no.
  ==> apt-file search /gtk/gtk.h
      apt-get install libgtk-3-dev

  (M2) on CentOS Stream 9

  configure: error: no acceptable C compiler found in $PATH
  ==> yum install gcc

  configure: error: "FATAL:term.h not found. Install ncurses-devel."
  ==> yum provides */term.h|grep ncurses
      yum install ncurses-devel

  configure: error: "FATAL:cups/cups.h not found. Install cups-devel."
  ==> yum provides */cups/cups.h
      yum install cups-devel

  checking for glib-2.0... no
  configure: error: "FATAL:libglib2 is required if libgnome2 is not installed"
  ==> yum provides */gtk.h
      yum install gtk3-devel

  (L) V129T

  (L2)= TroubleShooting for ./configure (case of CentOS stream 9. 2022/12/10).

      configure: error: no acceptable C compiler found in $PATH
      ==>yum install gcc

      configure: error: "FATAL:term.h not found. Install ncurses-devel."
      ==>yum provides */term.h|grep curses
         yum search ncurses-devel
         yum install ncurses-devel.x86_64

      configure: error: "FATAL:cups/cups.h not found. Install cups-devel."
      ===yum provides */cups/cups.h|grep devel
         yum search cups-devel
         yum install cups-devel.x86_64

      error: install GTK2(>=2.10.0) or GTK3(>=3.4.0) if NOT enable-gxe=no.
      ==>yum provides  gtk3
         yum search    gtk3-devel
         yum install   gtk3-devel.x86_64

      configure: error: !!! libgnome-2.0 installation required, OR specify --enable-libgnome2=no with glib-2.0 gio-2.0 installed.configure: error: !!! libgnome-2.0 installation required, OR specify --enable-libgnome2=no with glib-2.0 gio-2.0 installed.
      ==>./configure --enable-libgnome2=no

      Now, you can do make.

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

  (B1) "./configure" error

    (1) no acceptable C compiler found in $PATH
        ===> install gcc
             on debian8.10: apt-get install build-essential
    (2) crt1.o no such file   (Debian 4.0) 
        (suffix of development package differ for each distro)
        ===> install libglib2.0-dev
        ===> install libc6-dev (ubuntu8)
    (3) "term.h" not found
        ===> install ncurses-develop. 
        ncursesw/ncurses.h not found.
        ===> install ncursesw-develop. 
             (debian8.10)
                 apt-get install libncursesw5-dev
    (4) cups/cups.h not found.
        ===> install cups-devel
        ===> install libgnomecups1.0.dev (ubuntu8)
        ===> install libcupsys2-dev      (ubuntu9)
    (5) No package libgnomeui-2.0 found
        No package gnome-vfs-module-2.0 found
        No package libgnomeprint-2.2 found
        ===> install libgnomeui-devel
             install libgnomeprint-devel
        ===> install libgnomeui-dev
             install libgnomeprint2.2-dev  (ubuntu8)
        (mutual dependency may start another package installation)
     OR (gnome2 may obsoleted on the distribution)
        Use ./configure enable-libgnome2=no (glib2.0-dev install required)
        In that case, "gio.h" is missing will be shown.
    (6) pkg-config was not found
        ===> install pkg-config
    (7) CHK_INSTALL_GTK3...no and  CHK_INSTALL_GTK2..no
        ==>apt-file --package-only search gtk+-2.0
           apt-file --package-only search gtk+-3.0
           apt-get install libgtk2.0-dev
             or 
           apt-get install libgtk-3-dev
    (8) CHK_EXIST_GTK3_LIBGNOME2... no
        ===> install libgnome2-dev

  (B2) "make" error

    (1) "term.h" not found
        ===> install ncurses-develop. 
    (2) Cannot find the librarly libssl (On TurbolinuxFUJI trial version)
        ===> install openssp
    (3) Cannot find the librarly libpopt.la
        ===> install popt from ftp site
    (4) X error'BadDevice invalid or uninitialized device 168  (Ubuntu-7)
        :        major 145 .. minor 3 resource 0x00
        Failed to open Device
        ===> /etc/X11/xorg.conf was changed.

        Following lines are comment out

        ##Section "InputDevice"
        ##  Driver        "wacom"
        ##  Identifier    "stylus"
        ##  Option        "Device"        "/dev/wacom"          # Change to
        ##                                                      # /dev/input/event
        ##                                                      # for USB
        ##  Option        "Type"          "stylus"
        ##  Option        "ForceDevice"   "ISDV4"               # Tablet PC ONLY
        ##EndSection

        ##Section "InputDevice"
        ##  Driver        "wacom"
        ##  Identifier    "eraser"
        ##  Option        "Device"        "/dev/wacom"          # Change to
        ##                                                      # /dev/input/event
        ##                                                      # for USB
        ##  Option        "Type"          "eraser"
        ##  Option        "ForceDevice"   "ISDV4"               # Tablet PC ONLY
        ##EndSection

        ##Section "InputDevice"
        ##  Driver        "wacom"
        ##  Identifier    "cursor"
        ##  Option        "Device"        "/dev/wacom"          # Change to
        ##                                                      # /dev/input/event
        ##                                                      # for USB
        ##  Option        "Type"          "cursor"
        ##  Option        "ForceDevice"   "ISDV4"               # Tablet PC ONLY
        ##EndSection

                And in Section "ServerLayout"

        ##    InputDevice     "stylus" "SendCoreEvents"
        ##    InputDevice     "cursor" "SendCoreEvents"
        ##    InputDevice     "eraser" "SendCoreEvents"

    (5) /bin/sh' /usr/bin/esd: not found (Ubuntu-7)
        ===> install esound

  (B3) error at execution.

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
	(18)GnomePrint-CRITICAL **: gnome_rfont_get_glyph_stdadvance: assertion `glyph < GRF_NUM_GLYPHS (rfont)' failed
    	Unprintable char detected at gnome printing.

(C) FC11.s390x upgrade trouble shooting.

 !!! See (E)-FC14 for latest !!!

    Install required package over FC11 preinstalled DASD (http://secondary.fedoraproject.org/pub/alt/spins/S390/)
            ref           http://katzkichi-katzkichi.blogspot.com/2010/01/linux.html   (Japanese Page)
            pkg-download  //s390.koji.fedoraproject.org/koji

    (1) yum -y install libgnomeprint22-devel.s390x (pre-test for "yum upgrade")
          --> UnicodeDecodeError: 'ascii' codec can't decode byte 0xe5 in position 154: ordinal not in range(128)
              ==> Create new file.
                      /usr/lib/python2.6/site-packages/sitecustomize.py
                         import sys
                         sys.setdefaultencoding("utf-8")
          (yum install)
          --> Destination Host Prohibit
              ==> release firewall.
                      "iptables -F"
          (yum install)
          --> ERROR with rpm_check_debug vs depsolve
              Search package on //..koji.. for xz 4.999.8-0.7.beta and rpm 4.7.1-2.
              Download except dbginfo rpm then install all pkg in the page.
              (upload to s390x by scp the execute rpm on ssh console)
                scp fnm root@192.168.200.3:/root
                xz-libs:  rpm  -ivh   rpm*.rpm
                rpm    :  rpm  -Uvh   xz*.rpm
    (2) yum upgrade
          --->
             createrepo-0.9.8-2.fc12.noarch from fedora has depsolving problems
               --> Missing Dependency: python-deltarpm is needed by package createrepo-0.9.8-2.fc12.noarch (fedora)
             system-config-network-tui-1.5.99-1.fc12.noarch from fedora has depsolving problems
               --> Missing Dependency: python-iwlib is needed by package system-config-network-tui-1.5.99-1.fc12.noarch (fedora)
             Error: Missing Dependency: python-iwlib is needed by package system-config-network-tui-1.5.99-1.fc12.noarch (fedora)
             Error: Missing Dependency: python-deltarpm is needed by package createrepo-0.9.8-2.fc12.noarch (fedora)
              You could try using --skip-broken to work around the problem
              You could try running: package-cleanup --problems
                                     package-cleanup --dupes
                                     rpm -Va --nofiles --nodigest

        ===>yum install deltarpm
        ===>Install iwlib after searching on //..koji...
        ---> libiw, wireless-tools required.
        ===>yum install wiress-tools
        (yum took few hours on core4 CPU)

    (3) Restart.

        When selected new kernel(FC12) on hercules console.
        --->Boot wait by "No root device".   ===>give-up
        When selected old kernel(FC11)
        --->CTC error
        ===>Add 3 line to /etc/rc.sysinit("@@@" flaged lines) (This is existed before upgrade to FC12)
                # /bin/bash
                #
                # /etc/rc.d/rc.sysinit - run once at boot time
                #
                # Taken in part from Miquel van Smoorenburg's bcheckrc.
                #

                HOSTNAME=`/bin/hostname`

                set -m

                if   -f /etc/sysconfig/network !; then
                    . /etc/sysconfig/network
                fi
                if   -z "$HOSTNAME" -o "$HOSTNAME" = "(none)" !; then
                    HOSTNAME=localhost
                fi

            @@@ modprobe ctcm
            @@@ echo "0.0.0600,0.0.0601" > /sys/bus/ccwgroup/drivers/ctcm/group
            @@@ echo 1 > /sys/bus/ccwgroup/drivers/ctcm/0.0.0600/online
        (restart)
        --->"udevd error getting buffer for inotify"
        ===>yum -Uvh *udev*145-14* (update from release-7)
        --->Completed!   

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
(E) xe install log to fc14.s390x           2011/11/10
   00). (Linux)
        -base image is "fedora-14-s390x-20100925"
         (fedora-14-s390x.img is cause disk full soon at package installation) 
        -herclese is "hercules-3.07-1.i686.rpm"
        -adjust "hercles.cnf" 
          0120 3390 image-file-name
          (000C 3505 files(generic.prm,kernel..) are not used when IPL 120)
        -update hosts(add entry to "/etc/hosts")
           192.168.200.3 s390x
        	
   01). (s390x)
        #adduser useruser
        #asswd  useruser
   02). (s390x)
        -update DNS server("/etc/resolv.conf") reset at each IPL
          search example.com
          nameserver xxx.xxx.xxx.xxx 
          nameserver yyy.yyy.yyy.yyy    <--if secondary exists
            (/etc/resolv.conf is reset at each IPL
             to fix it, update /etc/sysconfig/network-scripts/ifcfg-ctc0
               DNS1=xxx.xxx.xxx.xxx
               DNS2=yyy.yyy.yyy.yyy
            )
        -update allow Xfowarding("/etc/ssh/sshd_config")
          X11Forwarding yes      <-- change from "no"
   03). (s390x)
        -update yum repository according http://fedoraproject.org/wiki/Architectures/s390x
          [fedora]
          name=Fedora $releasever - $basearch
          baseurl=http://s390.koji.fedoraproject.org/mash/rawhide/s390x/os/
          enabled=1
          gpgcheck=0
   ==> yum fails,ping to web fails by host prohibit
   04). (Linux)
        -drop REJECT entry from iptable entry
          #iptables -S         ->chk entry numver in the sequence
          #iptables -D INPUT n1  (n1 is entry number in INPUT chain(starting from 1))
          #iptables -D FORWARD n2  (n2 is entry number in FORWARD chain(starting from 1))
          #iptables -S         ->confirmation
   05). (Linux)
        -send gxe-vvv-tar.gz to s390
		  scp $SRCPATH/gxe-vvv.tar.gz useruser@s390x:gxe-vvv.tar.gz
   06). (s390x)
        -expand tgz,configure
          $tar -zxvf gxe-vvv.tar.gz         at /home/useruser
          $cd  gxe-vvv
          $./configure
   ==> no acceptable C compiler
        -install C 
          #yum install gcc.s390x
   ==> term.h not found
        -install ncurses
          #yum install ncurses-devel.s390x
   ==> yum WARNING: refresh-packagekit" inport failed
          #yum install PackageKit-yum-plugin.s390x
   ==> cups/cups.h not found
        -install cups
          #yum install cups-devel.s390x
   ==> no package libgnomeui,gnome-vfs-module,libgnomeprint,libgnomeprintui
        -install libs
          #yum install libgnomeui-devel.s390x
          #yum install libgnomeprintui22-devel.s390x
          (if yum hunged, #yum-complete-transaction)
   06). (s390x)
        -make
   ==> unknown type name ppd_file_t
        -cups/cups.h now dose not include ppd.h
        -gxe's xxecsub2 is corrected to include ppd.h
   ==> ld fails dlsym@@GLIBC_2.2...
        -ld spec changed at fc13
         2.so of "o.o"-->"1.so"-->"2.so" should not be implicit
        -gxe's Makefile is corrected to add "-ldl"
   ==> WARNING:unused but set
        -from gcc4.6 new option -Wunused-but-set-variable(default)
        -configure.in was changed to set -Wno-unused-but-set if gcc version>=4.6
         if required use config option like as "./configure --enable-unused-but-set=yes"
   07). (Linux)
        -test xe
        -test gxe
            ssh useruser@s390x gxe
   ==> cannot open display:
        #yum install xorg-x11-xauth.s390x
        (xhost on linux and setup DISPLAY= on s390x is done by ssh)
   ==> Japanese character is corrupted
        #yum groupinstall "Japanese Support"
   ==> GConf WARNING client failed to connect to the D-BUS deaemon
        #yum install dbus-x11.s390x
   ==> failed to load module pk-gtk-module
        #yum install PackageKit-gtk-module.s390x
   ==> xe: search for gnome-terminal failed
        #yum install gnome-terminal.s390x
   ==> IPP request failed with status 1280
        -libgnomeprint is polling CUPS but no printer available.
        -ignore it
   ==> Popup Dialog:An error occurred while loading or saving configuration information.
        -Use  not "su" but "su -".
   ==> GnomeUI-Warning:While connecting to session manager:None of authentication protocols specified are supported.
        -Use  not "su" but "su -".
   ==> Gtk-Message: Failed to load module "gnomebreakpad"
        -yum install bug-buddy (/usr/lib64/gtk-2.0/libgnomebreakpad)
        if not found, ignore it(this is of bug reporting system)

(F) xe install log to Ubunto11.10_x64       2011/11/21
   make
   ==> undefined symbol gnome_vfs_mime_get_default...
        install libgnomevfs2-extra
   ==> dlopen@@GLIBC_2.1 undefined 
        adjust LDFLAG of Makefile
   run gxe
   ==> Gtk-WARNING: Funable to locate theme engine in gtk-modules "pixbuf"
        "aptitude install gtk-engine-pixbuf"

(G) xe install test to OpenSuse12.1_x64      2011/11/22
	installed cups-devel, libgnomeui-devel, libgnomeprintui-devel
    (repository updated is required after DVD installation:"download.opensuse.org/distribution/12.1/repo/oss/suse")

(H) xe install test to Debian jessie 3.10 xfce
    xfce4-terminal
    	change shortcut key F1=help, F11=fullscreen, F10=Menu
        	run xfce4-appearance-settings, Settings, chk on "Enable editable accelerators"
            on xfce4-terminal,
            	Help-->Contents(showing "F1" at end), press "Del" key on the MenuItem.
            	View-->Fullscreen(showing "F11" at end), press "Del" key on the MenuItem.
                (This is registered on ~/.config/xfce4/terminal/accels.scm)
                Edit-->Preference(E)-->Advanced(V), check on "Disable MenuShortcut"
	WARNING **: Couldn't register with accessibility bus: Did not receive a reply. Possible causes include: the remote application did not send a reply, the message bus security policy blocked the reply, the reply timeout expired, or the network connection was broken.
            -->export NO_AT_BRIDGE=1 at elsewhere

    Gtk-WARNING **: Calling IsInhibited failed: GDBus.Error:org.freedesktop.DBus.Error.ServiceUnknown: The name org.gnome.SessionManager was not provided by any .service files
            -->Not harmfull,ignorable.
(I) Rspberry PI  2020/05/16
   configure on Emulator: image:"2020-02-13-raspbian-full" on QEMU3.1.0.
     ./configure get some err as followings.
        term.h not found
        -->#apt-get install libncurses-dev
        cups/cups.h not found
        -->#apt-get install libcups2-dev
        install GTK2 or GTK3
        -->#apt-get install libgtk-3-dev
        select libgnome2 or glib-2.0
        -->#apt-get install glib-2.0
        ==>./configure completed

(J) Manjaro gnome 20.1.2              2020/10/23 
         C compile not found          ==> pacman -S gcc
         ncursesw/ncurses.h not found ==> ./configure --enable-ncursesw=no
         pkg-config not found         ==> pacman -S pkg-config
         lingnome-2 required          ==> ./configure --enable-libgnome2=no
         correct make to qmake        ==> pacman -S make

         console version Backspec dose not work ==>  specify --7 option "xe --7B"
                  OR on Preference dialog, assign Ctrl-H to backspace, ASCII DEL to Delete key.

(K) Fedora33                          2020/12/09 
		missing term.h ==>yum install ncurses-devel
		missing cups/cups.h ==> yum install cups-devel
		install GTK2 or GTK3 ==>yum install gtk3-devel
		install libgnome2 OR --enable-libgnome2=no with glib2.0 installed
				==>./configure --enable-libgnome2=no ==>completed succssfully.
				(glib2.0(including gio.h) is installed by dependency of gtk3-devel)
		Check it that gio.h is refered by "pkg-config --cflags glib-2.0"
        (apt-file find xxx<==> dnf provides */xxx)
