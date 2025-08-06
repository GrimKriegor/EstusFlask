# Estus Flask lamp

Ambient light that resembles a flickering Estus Flask sitting on a stone base, with multiple modes of operation, namely regular Estus Flask and Ashen Estus Flask.


## Preview

<p float="left" align=center>
  <img src="https://github.com/GrimKriegor/EstusFlask/raw/main/pictures/idle.jpg" width="256" />
  <img src="https://github.com/GrimKriegor/EstusFlask/raw/main/pictures/red.gif" width="256" />
  <img src="https://github.com/GrimKriegor/EstusFlask/raw/main/pictures/blue.gif" width="256" />
</p>


## Getting

```
git clone --recursive https://github.com/GrimKriegor/EstusFlask.git
cd EstusFlask/
```

## Printing

### Flask

models/flask.blend

```
Material       | Clear PLA
Layer height   | 0.1 mm
Wall thickness | 0.8 mm
Temperature    | 195° C
Infill         | Concentric 5%
Supports       | None
Base adhesion  | Brim 8 mm
```

### Base

models/base.fcstd

```
Material       | Gray PLA
Layer height   | 0.2 mm
Wall thickness | 1.2 mm
Temperature    | 200° C
Infill         | Grid 15%
Supports       | Touching buildplate
Base adhesion  | Skirt
```

## Wiring

RGB LED connected to pins 9, 10 and 11 an USB powered AVR ATMega328p board through three 220 ohm resistors.



## Building and uploading the code

```
cd src/
make upload
```


## Attribuition

`models/flask.blend` is a fork of [Estus Flask by 3D2N](https://www.thingiverse.com/thing:1543005) licensed under the [Creative Commons - Attribution license](http://creativecommons.org/licenses/by/3.0/).
