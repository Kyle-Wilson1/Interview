import java.util.Arrays;
import java.util.List;

public class Main {

    public static void main(String[] args) {

        IpCheckService ipCheckService = new IpCheckServiceImpl();

        List<String> initIpList = Arrays.asList(
                "192.168.2.11",
                "192.168.2.12",
                "192.168.2.13"

        );

        // 初始化
        initIpList.forEach(ipCheckService::insert);

        System.out.println(ipCheckService.isInList("192.168.2.11"));
        System.out.println(ipCheckService.isInList("192.168.2.15"));

    }
}
