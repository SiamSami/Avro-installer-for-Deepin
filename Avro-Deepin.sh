sudo apt update
sudo apt install ibus ibus-m17n dconf-editor wget -y
echo "export GTK_IM_MODULE=ibus" >> /$HOME/.bashrc
echo "export XMODIFIERS=@im=ibus" >> /$HOME/.bashrc
echo "export QT_IM_MODULE=ibus" >> /$HOME/.bashrc
echo "ibus-daemon -drx" >> /$HOME/.bashrc
export GTK_IM_MODULE=ibus
export XMODIFIERS=@im=ibus
export QT_IM_MODULE=ibus
wget https://github.com/maateen/avro/releases/download/v2.1/avro_2.1-3_all.deb
sudo apt install ./avro_2.1-3_all.deb
rm avro_2.1-3_all.deb
dconf write /desktop/ibus/general/enable-by-default true
dconf write /desktop/ibus/general/use-system-keyboard-layout true
wget --no-check-certificate https://fahadahammed.com/extras/fonts/font.sh -O font.sh
chmod +x font.sh
bash font.sh
rm font.sh
im-config -n ibus 
echo "Please restart your computer"
