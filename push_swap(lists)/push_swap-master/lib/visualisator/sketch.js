let stack_b = [];
let com_words = ["sa", "sb", "ss", "ra", "rb", "rr", "rra", "rrb", "rrr", "pa", "pb"];
let values = [];
let i = 0;

function setup() {
  createCanvas(1280, 720);
  fps = new FPS();
  let gui_col = new dat.GUI();
  gui_col.add(fps, 'speed', 1, 100);
  //Generate numbers and commands
  //for(let i = 0;i<width/8;i++){
  //  stack_a.push(random(-height, height));
  //}
  //for(let i = 0;i<width;i++){
  //  commands.push(random(com_words));
  //}
  //Mashtab
  var max_of_stack_a = Math.max.apply(Math, stack_a);
  var min_of_stack_a = Math.min.apply(Math, stack_a);
  print(max_of_stack_a);
  print(min_of_stack_a);
  if (Math.abs(min_of_stack_a) > max_of_stack_a) {
    max_num_of_stack_a = Math.abs(min_of_stack_a);
      }
  else { max_num_of_stack_a = max_of_stack_a; }
  koeffy = max_num_of_stack_a/height;
  print(koeffy);
}

function draw() {
  frameRate(fps.speed);
  background(255);
  stroke(9, 161, 162);
  line(0, height/2, width, height/2);
  stroke(255, 255, 255);
  fill(9, 161, 162);
  text("Stack A", 5, height/2 + 12);
  text(max_num_of_stack_a, width - 30, height/2 + 12);
  text("- " + max_num_of_stack_a, width - 38, height - 12);
  text("0", width - 20, (height/4)*3);
  fill(244, 76, 128);
  text("Stack B", 5, 12);
  text(max_num_of_stack_a, width - 30, 12);
  text("- " + max_num_of_stack_a, width - 38, height/2 - 12);
  text("0", width - 20, height/4);
  run_commands();
  textSize(32);
  if (i != commands.length){
    fill(249, 154, 46);
    textStyle(BOLD);
    text(commands[i], width/2, height/2 - 12);
  }
  else { 
    fill(250, 172, 84);
    textStyle(BOLD);
    text("Yahoo!", width/2, height/2 - 12); 
  }
  textSize(12);
  draw_stack(stack_a, (height/4)*3, width/stack_a.length, 3, 53, 176, 178);
  draw_stack(stack_b, height/4, width/stack_a.length, 250, 244, 76, 128);
}


function FPS() {
	this.speed = 2;
}

function is_array_sorted(arr) {
  for(let i=0; i < arr.length - 1; i++) {
    if(arr[i] > arr[i+1]) {
       return false;
    }
  }
  return true;
}

//TODO - check run on good test. pa, pb - wrong with bad input
function run_commands(){
  if (i < commands.length){
    if (commands[i] == "sa"){
      try {
        if (stack_a[0] != undefined && stack_a[1] != undefined) {
          [stack_a[0], stack_a[1]] = [stack_a[1], stack_a[0]];
        }
      } catch (e) {
        print("Woos sa");}
      i++;
    }
    if (commands[i] == "sb"){
      try {
        if (stack_b[0] != undefined && stack_b[1] != undefined) {
          [stack_b[0], stack_b[1]] = [stack_b[1], stack_b[0]];
        }
      } catch (e) {
        print("Woos sb");}
      i++;
    }
    if (commands[i] == "ss"){
      try {
        if (stack_a[0] != undefined && stack_a[1] != undefined) {
          [stack_a[0], stack_a[1]] = [stack_a[1], stack_a[0]];
        } 
        if (stack_b[0] != undefined && stack_b[1] != undefined) {
          [stack_b[0], stack_b[1]] = [stack_b[1], stack_b[0]];
        }
      } catch (e) {
        print("Woos ss");}
      i++;
    }
    if (commands[i] == "ra"){
      try {
        if (stack_a[0] != undefined) {
          stack_a.push(stack_a.shift());
        }
      } catch (e) {
        print("Woos ra");}
      i++;
    }
    if (commands[i] == "rb"){
      try {
        if (stack_b[0] != undefined) {
          stack_b.push(stack_b.shift());
        }
      } catch (e) {
        print("Woos rb");}
      i++;
    }
    if (commands[i] == "rr"){
      try {
        if (stack_a[0] != undefined) {
          stack_a.push(stack_a.shift());
        }
        if (stack_b[0] != undefined) {
          stack_b.push(stack_b.shift());
        }
      } catch (e) {
        print("Woos rr");}
      i++;
    }
    if (commands[i] == "rra"){
      try {
        stack_a.unshift(stack_a[stack_a.length - 1]);
        stack_a.splice(stack_a.length - 1, 1);
      } catch (e) {
        print("Woos rra");}
      i++;
    }
    if (commands[i] == "rrb"){
      try {
        stack_b.unshift(stack_b[stack_b.length - 1]);
        stack_b.splice(stack_b.length - 1, 1);
      } catch (e) {
        print("Woos rrb");}
      i++;
    }
    if (commands[i] == "rrr"){
      try {
        stack_a.unshift(stack_a[stack_a.length - 1]);
        stack_a.splice(stack_a.length - 1, 1);
        stack_b.unshift(stack_b[stack_b.length - 1]);
        stack_b.splice(stack_b.length - 1, 1);
      } catch (e) {
        print("Woos rrr");}
      i++;
    }
    if (commands[i] == "pa"){
      try {
        if (stack_b[0] != undefined) {
          stack_a.unshift(stack_b[0]);
          stack_b.splice(0, 1);
        }
      } catch (e) {
      print("Woos pa");}
      i++;
    }
    if (commands[i] == "pb"){
      try {
        if (stack_a[0] != undefined) {
          stack_b.unshift(stack_a[0]);
          stack_a.splice(0, 1);
        }
      } catch (e) {
      print("Woos pb");}
      i++;
    }
  }
  else { 
    if (is_array_sorted(stack_a) && stack_b.length == 0) {
      Swal.fire({
        position: 'top-end',
        icon: 'success',
        customClass: {
          title: 'title-class-success'},
        title: 'HUYAK! Sorted',
        showConfirmButton: false,
        timer: 7000,
        backdrop: `
          rgba(0,0,30,0.4)
          url("win.gif")
          left top
          no-repeat
        `
      })
    }
    else {
    Swal.fire({
        position: 'top-end',
        icon: 'error',
        customClass: {
          title: 'title-class-error'},
        title: 'FUCK! Not sorted',
        showConfirmButton: false,
        timer: 7000,
        backdrop: `
          rgba(0,0,30,0.4)
          url("nyan.gif")
          left top
          no-repeat
        `
      })
    }
    noLoop();
    print("Done"); }
}

// draw rectangles
function draw_stack(stack, heighty, widthy, color, color_fill, color_g, color_b){
  for(let i = 0;i<stack.length;i++){
    stroke(color, 161, 162);
     fill(color_fill, color_g, color_b);
     rect(i*widthy , heighty, widthy, -stack[i]/(koeffy*4), 2);
   }
}