package ch_08.e0806;

public class Geometry {
    public static double cubeVolume(double h){
        return h*h*h;
    }

    public static double cubeSurface(double h){
        return 6*h*h;
    }

    public static double sphereVolume(double r){
        return 3 * r*r*r / 4;
    }

    public static double sphereSurface(double r){
        return 4 * Math.PI * r*r;
    }

    public static double cylinderVolume(double r, double h){
        return r*r * Math.PI * h;
    }

    public static double cylinderSurface(double r, double h){
        return 2 * r*r * Math.PI + 2 * Math.PI * r * h;
    }

    public static double coneVolume(double r, double h){
        return Math.PI * r * r * h / 3;
    }

    public static double coneSurface(double r, double h){
        return r*r * Math.PI + r*h * Math.PI;
    }

}
