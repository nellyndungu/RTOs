Accidentally pressed the BOOT button of the ESP32
Resulted to faulire to upload code and the ESP32 was in download mode
Solution: esptool.py instructions
1. Check if python is installed
>Use the cmd and type the command *python --version*
2. Install esptool.py
> Use the command *pip install esptool* in cmd
3. Identify the correct COM port eg COM7
4. Erase flash
>Use the command *python -m esptool --chip esp32 --port COM7 erase_flash*
> Hold down the BOOT button while running command until you see Stub running.... Then you can release.
5.  Upload code. It should upload successfully
