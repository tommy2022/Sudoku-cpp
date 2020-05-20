package sample;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

/**
 * [HelloWorld�̃A�N�V�����N���X]<br>
 * <br>
 * @author tarosa0001
 */
public class HelloWorldAction {
    /** ���K�[ */
    private Logger logger = LogManager.getLogger(HelloWorldAction.class);

    /** ���O */
    private String name;

    /**
     * [�A�N�V�������s����]<br>
     * HelloWorld���o�͂��鏈�������s����B<br>
     * ���s���郁�\�b�h�́Astruts.xml�Ŏw�肵�����\�b�h�����g�p���Ď�������B<br>
     * Struts2�ł̓A�N�V�����̏������ʂŃy�[�W�̑J�ڐ�����肷�邪�A
     * �����"success"�̌Œ蕶�����ԋp����B<br>
     * <br>
     * @return
     */
    public String execute() {
        logger.info("���͂��ꂽ�p�����[�^�́u{}�v�ł��B", name);
        return "success";
    }

    /**
     * [���O�擾����]<br>
     * ���O���擾���܂��B<br>
     * Struts2���t�H�[���ɓ��͂��ꂽ�l���p�����[�^�Ƃ��Ă���ہA
     * getter���g�p���邽�߁A�p�����[�^�Ƃ��Ďg�p���������́A
     * Action�N���X�̃v���p�e�B�Ƃ��Đ錾���Ă����Agetter��p�ӂ���B
     * <br>
     * @return ���O
     */
    public String getName() {
        return name;
    }

    /**
     * [���O�ݒ菈��]<br>
     * ���O��ݒ肵�܂��B<br>
     * getter���l�A�y�[�W�ԂŎ󂯓n�������l��setter��p�ӂ��Ă����B<br>
     * <br>
     * @param name ���O
     */
    public void setName(String name) {
        this.name = name;
    }
}