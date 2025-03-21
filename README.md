First it was fun to be on the same wavelength as Zach Latta, 
then it was fun to procrastinate on this for 4 months.

Game Play.
Use Google Chrome to run the waves.html
Google Chrome has implemented Web Serial API so you can use this.

USB control is a Teensy 4.0, with 2 max9814 microphones sendding a serial data stream.
There is a brief ambient noise correction running when the teensy is first initalized. 
a reset or recaluation would probably be a good feature to add in the future.
I expect noise drift, especialy in the enviorment where this will be operating.

Then chrome serial listens for the ambient corrected audio stream, and moves the boat.svg at the 
difference between the AB sensors. 

Reaching the far left is a win  for A, Reaching Far right is a win for B.

5 seconds later, game resumes at center.

