#include <linux/usb.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hid.h>

static int probe(struct usb_interface* interface,const struct usb_device_id* id){
	printk("USB KEYBOARD plugged");
	return 0;
}
static void disconnect(struct usb_interface* interface){
	printk("USB KEYBOARD DISCONNECTED");
}

static const struct usb_device_id id_table[]={
	{USB_INTERFACE_INFO
		(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT,
		 USB_INTERFACE_PROTOCOL_KEYBOARD)},
			{},
};
MODULE_DEVICE_TABLE(usb,id_table);

static struct usb_driver hello_driver={
	.name = "helloKey",
	.probe = probe,
	.disconnect = disconnect,
	.id_table = id_table,
};

static int __init init(void){
	int x;
	printk("HI I AM HERE");
	x = usb_register(&hello_driver);
	if(!x){
		printk("Registered Successfully");
	}
	return x;
}
static void __exit cleanup(void){
	printk("HI I AM going");
	usb_deregister(&hello_driver);
}
module_init(init);
module_exit(cleanup);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rishabh Dwivedi");
MODULE_DESCRIPTION("Just a module");
