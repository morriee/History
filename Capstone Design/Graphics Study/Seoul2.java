package com.za.code;
//Fig. 11.21: GridBagDemo2.java
//Demonstrating GridBagLayout constants.
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;


public class Seoul2 extends JFrame implements ItemListener {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	String A[]={"종로구","중구","용산구","성동구","광진구","동대문구","중랑구","성북구","강북구","도봉구",
            "노원구","은평구","서대문구","마포구","양천구","강서구","구로구","금천구","영등포구","동작구",
            "관악구","서초구","강남구","송파구","강동구"};
	boolean ap[];
	Checkbox As[];
	
	public Seoul2() {
		
		System.out.println("Demonstrating BoxLayout");
		final int SIZE=3;
		Container c=getContentPane();
		Box boxes[]=new Box[1];
		boxes[0]=Box.createVerticalBox();
		ap=new boolean[25];
		As=new Checkbox[25];
		for(int i=0;i<25;i++)ap[i]=true;
		for(int i=0;i<25;i++)
		{
			As[i]=new Checkbox( A[i]);
			As[i].addItemListener( this );
			boxes[0].add(As[i] );     
		}
		c.add(boxes[0],BorderLayout.EAST);
		setSize(1000,1000);
		show();
		
	}
	
public static void main(String[] args) {
	new Seoul2();
	}
	
   public void itemStateChanged( ItemEvent e )
   {
      // test state of each Checkbox
      for(int i=0;i<25;i++)ap[i]=As[i].getState();
   }
   
  private int mx,my;
  private Image mImage;
      double t[][]={{16339,42880,23757,73981,37634,54849,33917,97129,82271,75724,
            70819,53151,32486,42746,62929,34969,44844,17830,41855,44894,
            57227,54601,16197,46555,54932},
              {54112,60710,86755,135219,146252,147019,115116,172221,141996,146933,
               263941,136655,92583,154567,152101,202455,125374,72310,156884,169854,
               127610,137720,126557,178639,122052},
              {77812,60763,105005,135277,158963,160497,172251,204667,142061,159958,
               264044,192939,146827,172905,214849,242758,187965,103679,180352,184233,
               238367,185981,231886,292420,209723}
               };
double x[][]={{ 7100,20358,11727,35588,17443,25501,16122,43853,36366,35086,
            32709,23512,14410,18718,29484,17240,21383, 7469,18842,19796,
            21745,29267, 9855,26793,27322},
            {23498,28621,45001,63422,67070,68368,54654,76730,63198,68465,
             119518,60604,40976,67677,69192,94592,56221,30616,74229,74992,
             50675,80944,76776,90709,61361},
             {35476,28648,53285,63448,72749,74536,80577,91907,63231,74594,
             119567,85737,64769,75267,101350,111082,83846,44702,84999,81914,
             93184,109446,138390,149228,104195}             
             } ;
double y[][]={{ 8163,19970,10424,34099,17865,26012,15857,46780,40630,35601,
            33234,26899,16129,21297,29808,15759,20877, 9250,20422,22432,
            31316,22044, 5049,17048,24472},
            {26867,28386,35896,63945,70194,69498,53900,83859,70089,68694,
             124556,68199,45854,76376,73798,95289,61842,37350,72707,84330,
             67860,48435,41798,77442,53237},
             {36910,28410,44706,63966,76420,76032,81517,99316,70115,74789,
             124603,95666,72788,85882,100272,116689,92666,52451,83982,90859,
             128444,65626,79094,125414,93098}
             };
double p[][]={{210,727,227,545,237,341,197,474,579,473,
            268,275,221,248,293,144,238,172,232,244,
            240,299, 70,159,262},
            {695,998,830,997,919,915,668,841,999,917,
             999,708,630,898,709,834,666,697,869,924,
             535,754,545,611,582},
             {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
              1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
              1000,1000,1000,1000,1000}
             };

double xp,yp;
int sx,sy,sp; 

  public void paint(Graphics g){
for(int k=275;k<=775;k+=2){
     Dimension d=getSize();
    checkOffscreenImage();
    Graphics offG=mImage.getGraphics();
    offG.setColor(Color.white);
    offG.fillRect(0,0,d.width,d.height);
    paintOffscreen(mImage.getGraphics(),k,0);
    g.drawImage(mImage,0,0,null);
for(int i=1;i<10000000;i++);
    }
for(int k=775;k<=1000;k+=2){
     Dimension d=getSize();
    checkOffscreenImage();
    Graphics offG=mImage.getGraphics();
    offG.setColor(Color.white);
    offG.fillRect(0,0,d.width,d.height);
    paintOffscreen(mImage.getGraphics(),k,1);
    g.drawImage(mImage,0,0,null);
for(int i=1;i<10000000;i++);
    }
    }
    private void checkOffscreenImage(){
Dimension d=getSize();
if(mImage==null||mImage.getWidth(null)!=d.width||
mImage.getHeight(null)!=d.height){
  mImage=createImage(d.width,d.height);
    }
    
    
    }

public void paintOffscreen(Graphics g,int k,int j){
Graphics2D g2=(Graphics2D)g;  
double tx,ty,tt,kx;
    double ka,kb;

g.setColor(Color.black);
g.drawLine(100,100,100,700);
g.drawLine(100,700,700,700);
g.drawLine(100,100,700,100);
g.drawLine(700,700,100,700);
g.drawLine(700,100,700,700);
g.drawLine(100,700,700,100);
g.drawString("오세훈 지지율",700,700);
g.drawString("한명숙 지지율",100,100);
//g.setColor(new Color(237,26,59));
Ellipse2D e;
g2.setStroke(new BasicStroke(2));
if(j==0){ka=500;kb=275;}else{ka=225;kb=775;}
for(int i=0;i<25;i++){
  if(!ap[i])continue;
//else g.setColor(new Color(26,100,237));
//else g.setColor(new Color(22,200,52));
//else g.setColor(new Color(255,203,5));
//else g.setColor(new Color(147,149,152));
kx=p[j][i]+(p[j+1][i]-p[j][i])/ka*(k-kb);
tx=x[j][i]+(x[j+1][i]-x[j][i])*(kx-p[j][i])/(p[j+1][i]-p[j][i]);
ty=y[j][i]+(y[j+1][i]-y[j][i])*(kx-p[j][i])/(p[j+1][i]-p[j][i]);
tt=t[j][i]+(t[j+1][i]-t[j][i])*(kx-p[j][i])/(p[j+1][i]-p[j][i]);

xp=(int)(tx/tt*1000.)/1000.;
yp=(int)(ty/tt*1000.)/1000.;
if(xp-yp>0.02)g2.setPaint(new Color(26,100,237));
else if(xp-yp>-0.02)g2.setPaint(new Color(147,149,152));
else g2.setPaint(new Color(255,203,5));
sx=(int)(xp*1900);
sy=(int)(yp*1900);
sp=(int)(tt/3000.);
e=new Ellipse2D.Double(100+sx-600-sp/2,1300-sy-sp/2,sp,sp);
g2.fill(e);g2.setPaint(Color.black);
g2.draw(e);
//g.drawOval(100+sx-600-sp/2,1300-sy-sp/2,sp,sp);
sx+=sp/2;sy-=sp/2;
g.setColor(Color.black);g.drawString(A[i],sx-500-sp/2,1300-sy-sp/2);
}
}
     }

