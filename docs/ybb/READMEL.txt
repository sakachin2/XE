Contains following files

  xelnx%xever1%.tgz           :binary compiled on FC5
  gxe-%xever2%.tar.gz         :source package
                                 To build:   tar -xvf  tgzfile
                                             ./configure  
                                             ./make       
                                             ./make install  (install to /usr/local/bin)
  gxe-%xever2%-%rel%.src.rpm  :srpm package for rpm based destro user
                                 To build:   rpmbuild --rebuild srpmfile
  gxe-%xever2%-%rel%.i586.rpm :rpm package for rpm based destro user
                                 To install: rpm -ivh  rpmfile

  xelnxu%xever1%.tgz          :UTF8 version: binary compiled on FC5
  gxeu-%xever2%.tar.gz        :UTF8 version: source package
