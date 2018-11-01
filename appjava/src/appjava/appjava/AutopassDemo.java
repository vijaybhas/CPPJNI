package appjava;

import com.hp.autopassj.core.AutopassJ;
import com.hp.autopassj.core.config.AutopassJPropertyKeys;
import com.hp.autopassj.exception.AutopassJException;

import java.util.Properties;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;


public class AutopassDemo {

    private AutopassJ anAutopassJ;
    //private Lock aLock = new Lock();

    private ReentrantLock aLock = new ReentrantLock();

    public static void main(String[] args) {
        appjava.AutopassDemo apd = new appjava.AutopassDemo();

        /* Initialize an AutopassJ and AutopassJConsumable instances */
        apd.initAutopassJ();

        /* Calling Usage API */
        apd.commonAPI();


        System.exit(0);
    }

    private void initAutopassJ() {
        Properties autopassjProperties = new Properties();
        /* Property to set the AutoPass data directory path */
        autopassjProperties.setProperty(AutopassJPropertyKeys.DATA_DIR, ".\\data");
        /* Property to set the AutoPass license data source file path */
        autopassjProperties.setProperty(AutopassJPropertyKeys.LIC_FILE, ".\\data\\LicFile.txt");
        /* Property to set the product PD file path (demo PD file in this case) */
        autopassjProperties.setProperty(AutopassJPropertyKeys.PDF_PATH, ".\\pdf\\50045_2.0_SecureLogin_8.7.pd");
        autopassjProperties.setProperty(AutopassJPropertyKeys.ENABLE_CRYPTO_TYPE, "0");

        //    properties.setProperty("autopassj.enable.crypto.type", "0");

        try {
            anAutopassJ = new AutopassJ(autopassjProperties);
        } catch (AutopassJException e) {
            System.err.println("An exception occured while initializing AutopassJ!");
            e.printStackTrace();
            System.exit(1);
        }
    }

    private void commonAPI() {
        try {

            String tenant = "10.11.12.13";
            anAutopassJ.getUsageReporter().use(100454, "1", 5, null, System.currentTimeMillis(), tenant,false);
        } catch (AutopassJException e) {
            System.err.println("An exception occured while installing the Instant-On license key!");
            e.printStackTrace();
            System.exit(1);
        }
    }
}
