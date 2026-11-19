The issue: impossible to send only audio signal from a PC to a monitor, because DisplayPort & HDMI architecture requires an accompanying video stream/handshake to function https://en.wikipedia.org/wiki/DisplayPort#Main_link .

On (Arch) Linux CLI, e.g.:
⃝
cvlc /a_path/music.flac &
setterm --blank 1
⏺
: the latter cuts audio.

On (Arch) Linux KDE, e.g.:
playing audio
⃝
kscreen-doctor --dpms off
⏺
or "Turn off screen": cuts audio.

The solution: blacli (black CLI) & blagui (black GUI).

blacli is a Bash script:
execute it on CLI: black display, still audio
press any key: back to normal.

blagui is a Linux executable using SDL displaying a black image:
execute it on KDE: black display, still audio
press any key: back to normal.

blagui cuts audio on CLI, blacli obviously works also on Konsole.


The Arch Linux topic https://bbs.archlinux.org/viewtopic.php?id=315531 .

Thanks:
blacli https://bbs.archlinux.org/viewtopic.php?pid=2314531#p2314531 .
Google Gemini helped me for the C code of blagui.

Compiling blagui.c :
needs base-devel (Arch) Linux package then in the directory of blagui.c :
⃝
gcc -O2 blagui.c -o blagui $(pkg-config --cflags --libs sdl3)
⏺