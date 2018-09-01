import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;


class Circle2D {	
	public Point2D center;
	public double radius;
	
	public Circle2D(final Point2D center, double radius) {
		this.center = center;
		this.radius = radius;
	}
	
	public Circle2D(double x, double y, double radius) {
		center = new Point2D(x, y);
		this.radius = radius;
	}
	
	public Circle2D(final Point2D p1, final Point2D p2) {
		center = new Point2D((p1.x + p2.x) * 0.5, (p1.y + p2.y) * 0.5);
		radius = center.distanceTo(p1);
	}
	
	public Circle2D(final Point2D p1, final Point2D p2, final Point2D p3) {
		final double P2_MINUS_P1_Y = p2.y - p1.y;
		final double P3_MINUS_P2_Y =  p3.y - p2.y;

		if (P2_MINUS_P1_Y == 0.0 || P3_MINUS_P2_Y == 0.0) {
			center = new Point2D(0.0, 0.0);
			radius = 0.0;
		}
		else {
			final double A = -(p2.x - p1.x) / P2_MINUS_P1_Y;
			final double A_PRIME = -(p3.x - p2.x) / P3_MINUS_P2_Y;
			final double A_PRIME_MINUS_A = A_PRIME - A;
			
			if (A_PRIME_MINUS_A == 0.0) {
				center = new Point2D(0.0, 0.0);
				radius = 0.0;
			}
			else {
				final double P2_SQUARED_X = p2.x * p2.x;
				final double P2_SQUARED_Y = p2.y * p2.y;

				
				final double B = (P2_SQUARED_X - p1.x * p1.x + P2_SQUARED_Y - p1.y * p1.y) /
						         (2.0 * P2_MINUS_P1_Y);
				final double B_PRIME = (p3.x * p3.x - P2_SQUARED_X + p3.y * p3.y - P2_SQUARED_Y) /
						               (2.0 * P3_MINUS_P2_Y);
				
		
				final double XC = (B - B_PRIME) / A_PRIME_MINUS_A;
				final double YC = A * XC + B;
				
				final double DXC = p1.x - XC;
				final double DYC = p1.y - YC;
				
				center = new Point2D(XC, YC);
				radius = Math.sqrt(DXC * DXC + DYC * DYC);
			}
		}
	}
	
	public boolean containsAllPoints(final List<Point2D> points2d) {
		for (final Point2D p : points2d) {
			if (p != center && !containsPoint(p)) {
				return false;
			}
		}
		
		return true;
	}
	
	public boolean containsPoint(final Point2D p) {
		return p.distanceSquaredTo(center) <= radius * radius;
	}
	
	@Override
	public String toString() {
		return center.toString()  +  ", Radius: " + radius; 
	}
}

class Point2D {
	public double x;
	public double y;
	
	public Point2D(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
	public double distanceSquaredTo(final Point2D p) {
		final double DX = x - p.x;
		final double DY = y - p.y;
		
		return DX * DX + DY * DY;
	}
	
	public double distanceTo(final Point2D p) {
		return Math.sqrt(distanceSquaredTo(p));
	}
	
	public static boolean areColinear(final Point2D p1, final Point2D p2, final Point2D p3) {
		return Math.abs(p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)) == 0.0;
	}
	
	@Override
	public String toString() {
		return "X: " + x + ", Y: " + y; 
	}
}

public class E {
	private Random rand = new Random();
    
    public Circle2D minidisk(final List<Point2D> points) {
		return bMinidisk(points, new ArrayList<Point2D>());
    }
	
    private Circle2D bMinidisk(final List<Point2D> points, final List<Point2D> boundary) {
    	Circle2D minimumCircle = null;
		
		if (boundary.size() == 3) {
			minimumCircle = new Circle2D(boundary.get(0), boundary.get(1), boundary.get(2));
		}
		else if (points.isEmpty() && boundary.size() == 2) {
			minimumCircle = new Circle2D(boundary.get(0), boundary.get(1));
		}
		else if (points.size() == 1 && boundary.isEmpty()) {
			minimumCircle = new Circle2D(points.get(0).x, points.get(0).y, 0.0);
		}
		else if (points.size() == 1 && boundary.size() == 1) {
			minimumCircle = new Circle2D(points.get(0), boundary.get(0));
		}
		else {
			Point2D p = points.remove(rand.nextInt(points.size()));
			minimumCircle = bMinidisk(points, boundary);
			
			if (minimumCircle != null && !minimumCircle.containsPoint(p)) {
				boundary.add(p);
				minimumCircle = bMinidisk(points, boundary);
				boundary.remove(p);
				points.add(p);
			}
		}
				
		return minimumCircle;
    }
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0){
			int n = sc.nextInt();
			ArrayList<Point2D> a = new ArrayList<Point2D>();
			for(int i=0;i<n;++i){
				a.add(new Point2D((double)sc.nextInt(), (double)sc.nextInt()));
			}
			Circle2D ans = (new E()).minidisk(a);
			System.out.printf("%.2f %.2f %.2f\n", ans.center.x, ans.center.y, ans.radius);
			t--;
		}
	}
}