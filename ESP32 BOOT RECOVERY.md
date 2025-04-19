Accidentally pressed the BOOT button of the ESP32. <br>
Resulted to faulire to upload code and the ESP32 was in download mode. <br>
Solution: esptool.py instructions
1. Check if python is installed
>Use the cmd and type the command *python --version* <br>

![image](https://github.com/user-attachments/assets/965ec3ff-14cb-428f-9686-a4a59f0ca699)

2. Install esptool.py
> Use the command *pip install esptool* in cmd <br>

![image](https://github.com/user-attachments/assets/6276f895-24ff-415b-8f6c-22ef216ef916)

3. Identify the correct COM port eg COM7
4. Erase flash
>Use the command *python -m esptool --chip esp32 --port COM7 erase_flash*
> Hold down the BOOT button while running command until you see Stub running.... Then you can release.
5.  Upload code. It should upload successfully
