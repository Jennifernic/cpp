    #include <graphics.h> 
      int main()
      {
          int gd = DETECT, gm;
          char data[] = "C:\\Program Files (x86)\\mingw-w64\\i686-8.1.0-posix-dwarf-rt_v6-rev0\\mingw32\\libliblibbgi.a";
      
          initgraph(&gd, &gm, data);
	  //you can also do NULL for third parameter if you did above setup successfully
	  //example: initgraph(&gd, &gm, NULL);
          circle(200, 200, 100);
          getch();
          closegraph();
          return 0;
      }