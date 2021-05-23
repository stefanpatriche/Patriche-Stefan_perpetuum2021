# Titlu proiect: Mini Plotter 2D

## Componente necesare:

- 2 motoare pas cu pas din unitati optice reciclate
- 1 motor servo SG90
- Placuta de dezvoltate Arduino UNO
- Shield pentru control motoare L293D
- Modul wifi NodeMCU
- Modul LCD alfanumeric monocrom (cu conexiune I2C)

## Descriere functionalitati:

- functionalitatea principala este cea de plotare a unor poze/texte.
- functionalitati secundare:
    - conectarea unui ecran LCD monocrom prin intermediul protocolului I2C ce va afisa un mesaj cand plotarea este gata sau o mica animatie care indica nivelul de finalizarea al procesului
    - adaugarea unui led pentru semnalizarea finalizarii sau care semnaleaza ca mini plotter-ul este in functiune
    - in functie de cati pini o sa mai am liberi as vrea sa incerc si sa conectez un modul wifi prin care sa pot da comezi de printare pentru diferite desene presetate

## Diagrama de conectare a motoarelor la shield:
![Diagrama de conectare](./Photos/Wiring_diagram.jpg)


## Update 1:
- Pentru inceput, am desfacut cele 2 DVD Writere pentru a putea extrage motoarele pas cu pas din ele

![Poza drivere](./Photos/DVD_Writere_desfacute.jpeg)
![Poza motor pas cu pas](./Photos/Motor_pas_cu_pas.jpeg)
![Poza motoare pas cu pas](./Photos/Motoare.jpeg)

- Dupa care am incercat si am scris un cod de test pentru a verifica functionalitatea motoarelor pas cu pas

![Test stepper](./Photos/Testare_miscare_pas_cu_pas.jpeg)

- Pentru testul final am facut un test fit pentru a-mi face o idee cum o sa stea si o sa functioneze motoarele (se poate observa in video adaugat: Video_test_fit.mp4)

![Test fit](./Photos/Test_fit.jpg)


- Pentru montajul fizic m-am folosit de carcasele de DVD Writere si am adaugat ecranul lcd monocrom care sa afiseze mesaje legate de procesul de plotare

![Montaj final](./Photos/Montaj_fina+ecran.jpg)

- Am folosit si un modul wifi (NodeMCU) care se foloseste de protocolul de comunicatie UART pentru a comunica cu Arduino si a primi comenzi suplimentare pentru folosirea manuala

![Modul Wifi](./Photos/Modul_NodeMCU.jpg)


## Mod de functionare:

### Modul de functionare automat:

- Am folosit un program care comunica cu Arduino pe baza portului serial prin care este conectat cu calculatorul, acesta citeste un fisier GCODE (care contine informatiile pentru a misca motoarele) si trimite linie cu linie comenzile catre Arduino care le interpreteaza si misca motoarele in functie de acestea

![Program trimitere info](./Photos/Gctrl.jpg)

### Modul de functionare manual:

- Modulul NodeMCU l-am legat prin protocolul UART de placuta Arduino (shield-ul folosit pentru controlul motoarelor ocupa toti pinii digitali + RX si TX asa ca am fost nevoit sa imi creez alti pini pentru conexiunea seriala cu ajutorul unei librarii la pinii analogici A0 si A1)

- Cu ajutorul modulului si cu aplicatia Blynk instalata pe telefon am diferite moduri de a controla manual motoarele:
    - Fie cu ajutorul a 4 butoane care incrementeaza/decrementeaza motoarele cu 2mm pe apasare si un buton pentru ridicarea si coborarea pixului
    - Cu ajutorul a 2 slidere prin care pot sa pozitionez exact distanta la care sa fie ambele motoare si un boton care ridica si coboara pixul
    - Cu ajutorul unui joystick prin care pot sa mut capul de desenare pe cele 2 axe X si Y de control si un buton de ridicare si coborare al pixului
    ![Functionare manuala](./Photos/Functionare_manuala1.jpg)
    ![Functionare manuala](./Photos/Functionare_manuala2.jpg) 
