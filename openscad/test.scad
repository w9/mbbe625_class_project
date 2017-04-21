$fn = 50;

HEIGHT = 7.5;
WIDTH = 7.5;
THICKNESS = 0.1;
INSET = 0.5;
GAP_DISTANCE = 0.5;
HOLE_SIZE = 0.125;

module hole(delta) {
  translate(delta)
    rotate(90, [1, 0, 0])
      color("blue") {
        cylinder(THICKNESS + 0.1, r = HOLE_SIZE, center = true);
      }
}

module board(delta) {
  translate(delta)
    difference() {
      color("yellow")
        cube([WIDTH, THICKNESS, HEIGHT], center = true);
      union() {
        hole([WIDTH / 2 - INSET, 0, HEIGHT / 2 - INSET]);
        hole([-WIDTH / 2 + INSET, 0, HEIGHT / 2 - INSET]);
        hole([-WIDTH / 2 + INSET, 0, -HEIGHT / 2 + INSET]);
        hole([WIDTH / 2 - INSET, 0, -HEIGHT / 2 + INSET]);
      }
    }
}

module screw(delta) {
  translate(delta)
    translate([0, (GAP_DISTANCE + THICKNESS)/2, 0])
      rotate(90, [1, 0, 0])
        color("red")
          cylinder(THICKNESS * 2 + GAP_DISTANCE, r = HOLE_SIZE, center = true);
}

board([0,0,0]);
board([0,GAP_DISTANCE + THICKNESS,0]);

screw([WIDTH / 2 - INSET, 0, HEIGHT / 2 - INSET]);
screw([-WIDTH / 2 + INSET, 0, HEIGHT / 2 - INSET]);
screw([-WIDTH / 2 + INSET, 0, -HEIGHT / 2 + INSET]);
screw([WIDTH / 2 - INSET, 0, -HEIGHT / 2 + INSET]);
