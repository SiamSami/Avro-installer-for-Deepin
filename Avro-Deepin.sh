sudo apt update
sudo apt install git libibus-1.0-dev automake autoconf make gjs ibus ibus-m17n dconf-editor wget fonts-noto-core -y
echo "export GTK_IM_MODULE=ibus" >> $HOME/.profile
echo "export XMODIFIERS=@im=ibus" >> $HOME/.profile
echo "export QT_IM_MODULE=ibus" >> $HOME/.profile
echo "ibus-daemon -drxR" >> $HOME/.profile
export GTK_IM_MODULE=ibus
export XMODIFIERS=@im=ibus
export QT_IM_MODULE=ibus
git clone git://github.com/sarim/ibus-avro.git
cd ibus-avro
aclocal && autoconf && automake --add-missing
./configure --prefix=/usr
make
sudo make install
dconf write /desktop/ibus/general/enable-by-default true
dconf write /desktop/ibus/general/use-system-keyboard-layout true
im-config -n ibus 
echo "Please restart your computer"
