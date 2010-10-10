%define version 1.7.3
%define release 1
%define	enable	1

Summary: User monitoring and command logging
Name: snoopy
Version: %{version}
Release: %{release}
URL: https://sourceforge.net/projects/snoopylogger/
Source: https://downloads.sourceforge.net/project/snoopylogger/snoopy-%{version}.tar.gz
Group: Applications/Monitoring
BuildRoot: %{_tmppath}/%{name}-buildroot
#BuildRequires: readline-devel
License: GNU GPL
Patch1: %{name}-%{version}_64bit.patch
Patch2: %{name}-%{version}_ttyname.patch
Packager: Aldemir Akpinar <aldemira@sf.net>

%description
Snoopy Logger, logs all the commands issued by local users on the system.
It is very useful to track and monitor the users.

%prep
%setup -q
%patch1
%patch2

%build

%configure
make DESTDIR=%{buildroot}

%install
rm -rf %{buildroot}
make install DESTDIR=%{buildroot}

%if %enable
install -d -m 755 $RPM_BUILD_ROOT/etc
if [ ! -f /etc/ld.so.preload ];then
echo "%{_libdir}/snoopy.so" >> $RPM_BUILD_ROOT/etc/ld.so.preload
fi
%endif

%clean
rm -rf %{buildroot}

#%post

%files
%defattr(644 root root 755)
%doc COPYING ChangeLog README* RELEASES
%config /etc/ld.so.preload
%{_libdir}/snoopy.so
