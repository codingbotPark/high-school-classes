class Rectangle{
    constructor(width,height){
        this.width = width;
        this.height = height;
    }

    // static property
    static typeName = 'Rectangle';
    static info() {
        return `Type: ${Rectangle.typeName}`;
    }
    getArea(){
        return this.width * this.height;
    }
}

const r = new Rectangle(10,10)
console.log(r.getArea())
console.log(Rectangle.typeName)
console.log(Rectangle.info());